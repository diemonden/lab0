#include "Command.h"
void Command::scale(TriangleSoup &Mesh, const Vec &CENTER, const double ScaleParameter) {
	for (Facet &point : Mesh) {
		for (int i = 0; i < 3; i++) {
			point.pos[i] = point.pos[i] * ScaleParameter + CENTER;
		}
	}
}