# C++ Projekt – Teile und Schritte Verarbeitung

Dieses Projekt liest zwei Dateien (`teile.dat` und `schritt.dat`) ein und erzeugt daraus eine Ausgabedatei (`output.dat`).

## 📁 Dateien im Repository

- programm.cpp – Der vollständige C++-Code
- teile.dat – Beispieldaten der verfügbaren Teile
- schritt.dat – Arbeitsschritte zur Verarbeitung

## ▶️ Ausführen des Programms

### Kompilieren (mit g++):
g++ -std=c++17 programm.cpp -o programm

### Ausführen:
./programm teile.dat schritt.dat

Dadurch entsteht automatisch die Datei:
output.dat

## 📝 Beschreibung

- Das Programm liest Teile aus der Datei *teile.dat*
- Es liest Arbeitsschritte aus der Datei *schritt.dat*
- Es ordnet alle Arbeitsschritte den passenden Teilen zu
- Die Ausgabe wird strukturiert in *output.dat* gespeichert

## 🧑‍💻 Voraussetzungen

- C++17 kompatibler Compiler (z. B. g++)
- VS Code oder ein anderer Editor
- Windows, Linux oder macOS
