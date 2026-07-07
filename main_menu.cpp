/***
 ============================================================
  DSL MUSICAL -- COMPILADOR
  Análisis Léxico y Sintáctico
  
  Archivo: main_menu.cpp
  Descripción: Versión con menú interactivo para seleccionar
               archivos .mus de la carpeta ejemplos/
 ============================================================
***/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include "analizador_lexico.h"
#include "analizador_sintactico.h"

using namespace std;

// ============================================================
// Función para listar archivos .mus de la carpeta ejemplos/
// ============================================================
vector<string> listarArchivosMusica() {
    vector<string> archivos;
    DIR *dir = opendir("ejemplos");
    
    if (dir != nullptr) {
        struct dirent *entrada;
        while ((entrada = readdir(dir)) != nullptr) {
            string nombre = entrada->d_name;
            // Filtrar solo archivos .mus
            if (nombre.length() > 4 && 
                nombre.substr(nombre.length() - 4) == ".mus") {
                archivos.push_back(nombre);
            }
        }
        closedir(dir);
    }
    
    sort(archivos.begin(), archivos.end());
    return archivos;
}

// ============================================================
// Mostrar menú y seleccionar archivo
// ============================================================
string mostrarMenuArchivos() {
    vector<string> archivos = listarArchivosMusica();
    
    if (archivos.empty()) {
        cout << "\n  No se encontraron archivos .mus en la carpeta ejemplos/\n";
        return "";
    }
    
    cout << "\n  ╔════════════════════════════════════════╗\n";
    cout << "  ║  Archivos disponibles:                 ║\n";
    cout << "  ╚════════════════════════════════════════╝\n\n";
    
    for (size_t i = 0; i < archivos.size(); i++) {
        cout << "  " << (i + 1) << ". " << archivos[i] << "\n";
    }
    
    cout << "\n  Seleccione un número (1-" << archivos.size() << "): ";
    int opcion;
    cin >> opcion;
    
    if (opcion >= 1 && opcion <= (int)archivos.size()) {
        return "ejemplos/" + archivos[opcion - 1];
    }
    
    cout << "\n  Opción inválida.\n";
    return "";
}

// ============================================================
// MAIN
// ============================================================
int main(int argc, char *argv[]) {
    cout << "\n";
    cout << "╔══════════════════════════════════════════╗\n";
    cout << "║   DSL MUSICAL -- COMPILADOR             ║\n";
    cout << "║   Análisis Léxico y Sintáctico          ║\n";
    cout << "║   Curso: Compiladores                   ║\n";
    cout << "╚══════════════════════════════════════════╝\n";

    // Determinar archivo a procesar
    string archivo;
    
    if (argc > 1) {
        // Si se pasa como argumento, usarlo
        archivo = argv[1];
        if (archivo.find("/") == string::npos && archivo.find("\\") == string::npos) {
            archivo = "ejemplos/" + archivo;
        }
    } else {
        // Si no hay argumento, mostrar menú
        archivo = mostrarMenuArchivos();
    }
    
    if (archivo.empty()) {
        return 1;
    }

    AnalizadorLexico *lexer = new AnalizadorLexico("");

    // Intentar leer archivo
    if (lexer->leerArchivo(archivo.c_str())) {
        cout << "\n  Archivo: " << archivo << "\n";
    } else {
        cout << "\n  Archivo '" << archivo << "' no encontrado.\n";
        delete lexer;
        return 1;
    }

    lexer->MostrarFuente();

    // Análisis Léxico
    if (lexer->Lexico()) {
        // Análisis Sintáctico
        AnalizadorSintactico *parser = new AnalizadorSintactico(lexer);
        parser->Sintactico();
        delete parser;
    }

    delete lexer;
    return 0;
}
