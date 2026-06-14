#ifndef ANALIZADOR_SINTACTICO_H
#define ANALIZADOR_SINTACTICO_H

#include "analizador_lexico.h"

// ============================================================
//  CLASE: Analisis Sintactico
// ============================================================
class AnalizadorSintactico {
    private:
        AnalizadorLexico *lexer;
        int tokenActual;

    public:
        AnalizadorSintactico(AnalizadorLexico *lex) {
            lexer = lex;
            tokenActual = -1;
        }

        // ── Metodo principal del analisis sintactico ──
        bool Sintactico() {
            cout << "\n" << string(78, '=') << "\n";
            cout << "  ANALISIS SINTACTICO -- DSL Musical\n";
            cout << string(78, '=') << "\n";
            cout << "  Pendiente para la siguiente fase...\n";
            cout << string(78, '=') << "\n\n";
            return true;
        }

        // ── Metodos para implementar reglas gramaticales ──
        // Estos seran expandidos en futuras iteraciones

        bool programa() {
            // <programa> ::= <declaraciones> <pentagramas> FIN
            return true;
        }

        bool declaraciones() {
            // <declaraciones> ::= <declaracion> | <declaraciones> <declaracion>
            return true;
        }

        bool pentagrama() {
            // <pentagrama> ::= PENTAGRAMA <numero> <configuracion> <compases>
            return true;
        }

        bool compas() {
            // <compas> ::= <nota> | <silencio> | <bloque_repetir>
            return true;
        }

        bool nota() {
            // <nota> ::= <nombre_nota> [<alteracion>] : <duracion>
            return true;
        }

        bool alteracion() {
            // <alteracion> ::= # | b
            return true;
        }
};

#endif // ANALIZADOR_SINTACTICO_H
