# Estructura del Proyecto DSL Musical - Compilador

## Descripción General
Este proyecto implementa un compilador para un Lenguaje Específico del Dominio (DSL) musical con soporte para partituras musicales en formato textual.

## Estructura de Archivos

```
HOla/
├── analizador_lexico.h      # Header con análisis léxico
├── analizador_sintactico.h  # Header con análisis sintáctico
├── main.cpp                 # Punto de entrada del compilador
├── README.md                # Documentación del proyecto
├── compilador               # Ejecutable compilado
└── ejemplos/                # Carpeta con archivos de entrada
    ├── partitura.mus
    ├── basico.mus
    ├── basico2.mus
    ├── basico3.mus
    ├── intermedio.mus
    ├── intermedio1.mus
    ├── intermedio2.mus
    ├── intermedio3.mus
    ├── complejo3.mus
    ├── apartitura_compleja.mus
    ├── mi_partitura.mus
    └── partitura_errores.mus
```

## Descripción de Componentes

### 1. `analizador_lexico.h`
**Responsabilidad**: Análisis léxico (tokenización)

**Contenido**:
- **Definiciones de Tokens**: Constantes #define para:
  - Palabras clave (HOJA, TITULO, AUTOR, PENTAGRAMA, etc.)
  - Notas musicales (DO, RE, MI, FA, SOL, LA, SI, SILENCIO)
  - Duraciones (NEGRA, BLANCA, REDONDA, CORCHEA, etc.)
  - Instrumentos (PIANO, GUITARRA, VIOLIN, etc.)
  - Signos especiales (:, |, {, }, (, ), #, b)
  - Códigos de error léxico (EL1-EL4)

- **Clase `Atributos`**: Estructura que almacena información de un token
  - `lexema`: Texto reconocido
  - `token`: Código numérico del token
  - `tipo`: Categoría del token
  - `valor`: Valor semántico
  - `estado`: Estado actual

- **Clase `TablaSimbolos`**: Tabla hash para gestionar tokens reconocidos
  - Métodos: Insertar, Buscar, ActualizarValor, etc.

- **Clase `AnalizadorLexico`**: Implementa el AFD (Autómata Finito Determinista)
  - `getToken()`: Lee el próximo token
  - `Lexico()`: Realiza análisis léxico completo
  - `leerArchivo()`: Carga archivos DSL
  - `MostrarFuente()`: Imprime código fuente numerado

### 2. `analizador_sintactico.h`
**Responsabilidad**: Análisis sintáctico (parsing)

**Contenido**:
- **Clase `AnalizadorSintactico`**: Valida estructura gramatical
  - `Sintactico()`: Método principal (en desarrollo)
  - Métodos stub para reglas gramaticales:
    - `programa()`: Estructura completa del DSL
    - `declaraciones()`: Declaraciones de hoja, título, autor
    - `pentagrama()`: Definición de pentagramas
    - `compas()`: Compases y notas
    - `nota()`: Análisis de notas con alteraciones
    - `alteracion()`: Sostenidos y bemoles

### 3. `main.cpp`
**Responsabilidad**: Punto de entrada e integración

**Flujo**:
1. Intenta leer archivo `partitura.mus`
2. Si no existe, usa ejemplo embebido
3. Muestra código fuente numerado
4. Ejecuta análisis léxico
5. Ejecuta análisis sintáctico (si léxico es exitoso)
6. Libera memoria

## Cómo Compilar

```bash
cd "/home/emerson/5to Semestre/Compiladores/Trabajo/HOla"
g++ -fdiagnostics-color=always -g main.cpp -o compilador
```

## Cómo Ejecutar

```bash
./compilador
```

## Errores Léxicos Detectados

| Código | Error | Descripción |
|--------|-------|-------------|
| EL1 | Cadena sin cerrar | `"...` sin cierre |
| EL2 | Fracción mal formada | `N/` sin denominador |
| EL3 | Identificador desconocido | Palabra no reconocida |
| EL4 | Carácter ilegal | Símbolo no permitido |

## Ventajas de esta Estructura

✅ **Separación de responsabilidades**: Cada módulo tiene una función clara
✅ **Reutilizable**: Los headers pueden usarse en otros proyectos
✅ **Extensible**: Fácil agregar reglas gramaticales nuevas
✅ **Mantenible**: Código organizado y documentado
✅ **Escalable**: Facilita agregar análisis semántico futuro

## Próximas Extensiones

1. Implementar reglas gramaticales completas en `analizador_sintactico.h`
2. Agregar análisis semántico
3. Generación de código intermedio
4. Optimizaciones
5. Generación de audio/MIDI

---
**Nota**: Los archivos `.mus` se encuentran en la carpeta `ejemplos/` y se leen automáticamente al ejecutar el compilador.
