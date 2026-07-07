# 📖 Cómo usar el Compilador DSL Musical

## 🚀 Formas de ejecutar

### Opción 1: Línea de comandos (RECOMENDADA)

**1. Con nombre corto** (busca en `ejemplos/` automáticamente)
```bash
./compilador basico.mus
./compilador basico2.mus
./compilador intermedio.mus
./compilador complejo3.mus
```

**2. Con ruta completa**
```bash
./compilador ejemplos/partitura.mus
```

**3. Sin argumentos** (usa `partitura.mus` por defecto)
```bash
./compilador
```

---

### Opción 2: Menú Interactivo

Si quieres seleccionar el archivo de una lista:
```bash
./compilador_menu
```

Muestra un menú como este:
```
  ╔════════════════════════════════════════╗
  ║  Archivos disponibles:                 ║
  ╚════════════════════════════════════════╝

  1. apartitura_compleja.mus
  2. basico.mus
  3. basico2.mus
  4. basico3.mus
  5. complejo3.mus
  6. intermedio.mus
  7. intermedio1.mus
  8. intermedio2.mus
  9. intermedio3.mus
  10. mi_partitura.mus
  11. partitura.mus
  12. partitura_errores.mus

  Seleccione un número (1-12):
```

Escribes el número y presionas Enter.

---

## 📁 Archivos disponibles en `ejemplos/`

| Archivo | Descripción |
|---------|-------------|
| `basico.mus` | Ejemplo simple con 4 notas |
| `basico2.mus` | Ejemplo mínimo con melodía |
| `basico3.mus` | Otro ejemplo básico |
| `intermedio.mus` | Complejidad media |
| `intermedio1.mus` | Medio con más estructuras |
| `intermedio2.mus` | Variante intermedia |
| `intermedio3.mus` | Otro nivel intermedio |
| `complejo3.mus` | Código más complejo |
| `apartitura_compleja.mus` | Partitura compleja |
| `mi_partitura.mus` | Ejemplo personalizado |
| `partitura.mus` | Partitura por defecto |
| `partitura_errores.mus` | Partitura con errores intencionales |

---

## 💡 Ejemplos de uso

```bash
# Compilar archivo básico
./compilador basico.mus

# Compilar con ruta completa
./compilador ejemplos/intermedio.mus

# Usar menú interactivo
./compilador_menu
# Luego escribes: 3

# Usar archivo por defecto
./compilador
```

---

## 🔍 Salida esperada

Para cualquier opción, verás:

1. **Encabezado** del compilador
2. **Nombre del archivo** procesado
3. **Código fuente numerado** por líneas
4. **Tabla de análisis léxico** con tokens
5. **Resumen** (tokens, errores, líneas)
6. **Análisis sintáctico** (pendiente)

---

## 🛠️ Archivos fuente

- **`main.cpp`** - Versión por línea de comandos
- **`main_menu.cpp`** - Versión con menú interactivo
- **`analizador_lexico.h`** - Análisis léxico (AFD)
- **`analizador_sintactico.h`** - Análisis sintáctico (skeleton)

**Usa ambas versiones según necesites:**
```bash
g++ -g main.cpp -o compilador       # Línea de comandos
g++ -g main_menu.cpp -o compilador_menu  # Con menú
```
