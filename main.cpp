/***
 ============================================================
  DSL MUSICAL -- COMPILADOR
  Análisis Léxico y Sintáctico
  
  Archivo: main.cpp
  Descripción: Punto de entrada del compilador que integra
               el análisis léxico y sintáctico.
 ============================================================
***/

#include <fstream>
#include "analizador_lexico.h"
#include "analizador_sintactico.h"

int main() {
    cout << "\n";
    cout << "╔══════════════════════════════════════════╗\n";
    cout << "║   DSL MUSICAL -- COMPILADOR             ║\n";
    cout << "║   Análisis Léxico y Sintáctico          ║\n";
    cout << "║   Curso: Compiladores                   ║\n";
    cout << "╚══════════════════════════════════════════╝\n";

    const char archivo[] = "ejemplos/partitura.mus";
    AnalizadorLexico *lexer = new AnalizadorLexico("");

    // Intentar leer archivo
    if (lexer->leerArchivo(archivo)) {
        cout << "\n  Archivo: " << archivo << "\n";
    } else {
        cout << "\n  Archivo '" << archivo << "' no encontrado. Usando ejemplo embebido.\n";
        
        // Crear nuevo lexer con ejemplo si no hay archivo
        delete lexer;
        const char src[] =
            "HOJA A4\n"
            "TITULO \"Nocturno en Re Menor\"\n"
            "AUTOR  \"Ana Torres\"\n"
            "\n"
            "PENTAGRAMA 1\n"
            "CLAVE      SOL\n"
            "COMPAS     3/4\n"
            "TEMPO      90\n"
            "VOLUMEN    80\n"
            "INSTRUMENTO PIANO\n"
            "\n"
            "// Compas 1 - melodia con alteraciones\n"
            "RE:NEGRA\n"
            "FA#:NEGRA\n"
            "LA:BLANCA |\n"
            "\n"
            "// Modo menor\n"
            "CLAVE MENOR\n"
            "MIb:CORCHEA\n"
            "SOL:CORCHEA\n"
            "SI:NEGRA |\n"
            "\n"
            "// Bloque REPETIR\n"
            "REPETIR {\n"
            "    DO:SEMICORCHEA\n"
            "    RE:SEMICORCHEA\n"
            "    MI:FUSA\n"
            "    FA:FUSA |\n"
            "}\n"
            "FIN_REPETIR\n"
            "\n"
            "// Silencio y cierre\n"
            "SILENCIO:REDONDA |\n"
            "\n"
            "// --- Errores intencionales ---\n"
            "TITULO \"cadena sin cerrar\n"
            "TEMPO 4/\n"
            "XILOFONO\n"
            "DO:NEGRA @ |\n";
        
        lexer = new AnalizadorLexico(src);
    }

    // ── Mostrar codigo fuente ──
    lexer->MostrarFuente();

    // ── Analisis Lexico ──
    if (lexer->Lexico()) {
        // ── Analisis Sintactico ──
        AnalizadorSintactico *parser = new AnalizadorSintactico(lexer);
        parser->Sintactico();
        delete parser;
    }

    delete lexer;
    system("pause");
    return 0;
}
