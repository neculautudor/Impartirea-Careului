#ifndef HEADER_FILE
#define HEADER_FILE

#define NUMAR_NIVELE 10
#define NUMAR_BULINE 8

struct Coordonate {
	int x, y;
};

struct Nivel {
	Coordonate buline[NUMAR_BULINE];
} nivele[NUMAR_NIVELE];

#endif