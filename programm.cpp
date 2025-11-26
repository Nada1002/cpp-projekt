#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

struct Teil
{
	std::string typ;
	std::string bez;
	std::string einheit;
	double gewicht;
	double preis;
};

struct Schritt
{
	int nr;
	std::string quellTyp;
	std::string quellBez;
	int menge;
	std::string taetigkeit;
	int zeit;
};

using Key = std::pair<std::string, std::string>;

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cerr << "Benutzung: programm <teile.dat> <schritt.dat>\n";
		return 1;
	}

	std::ifstream fteile(argv[1]);
	std::ifstream fschritt(argv[2]);

	if (!fteile)
	{
		std::cerr << "Kann Datei nicht öffnen: " << argv[1] << "\n";
		return 1;
	}
	if (!fschritt)
	{
		std::cerr << "Kann Datei nicht öffnen: " << argv[2] << "\n";
		return 1;
	}

	std::map<Key, Teil> teile;
	Teil t;

	while (fteile >> t.typ >> t.bez >> t.einheit >> t.gewicht >> t.preis)
	{
		teile[{t.typ, t.bez}] = t;
	}

	std::map<Key, std::vector<Schritt>> schritte;

	while (true)
	{
		Schritt s;
		std::string zielTyp, zielBez;

		if (!(fschritt >> zielTyp >> zielBez >> s.nr >> s.quellTyp >> s.quellBez >> s.menge >> s.taetigkeit >> s.zeit))
			break;

		schritte[{zielTyp, zielBez}].push_back(s);
	}

	std::ofstream out("output.dat");

	for (const auto &p : teile)
	{
		const Key &k = p.first;
		const Teil &t = p.second;

		out << "TEIL "
			<< t.typ << " " << t.bez << " "
			<< t.einheit << " " << t.gewicht << " " << t.preis
			<< "\n";

		auto it = schritte.find(k);
		if (it != schritte.end())
		{
			for (const Schritt &s : it->second)
			{
				out << "  SCHRITT "
					<< s.nr << " "
					<< s.quellTyp << " " << s.quellBez << " "
					<< s.menge << " "
					<< s.taetigkeit << " "
					<< s.zeit << "\n";
			}
		}
	}

	return 0;
}
