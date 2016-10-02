#include "strangecube.hpp"

#include <logger.hpp>


StrangeCube::StrangeCube(const Color& mainColor,
				   const Color& bordersColor)
	: Mesh()
{
	logDebug << "Strange cube init started" << logEnd;

	// vertices.
	{
		addVertex(Vertex(-1.0, -1.0, -1.0, mainColor));
		addVertex(Vertex(1.0, -1.0, -1.0, mainColor));
		addVertex(Vertex(-1.0, 1.0, -1.0, mainColor));
		addVertex(Vertex(1.0, 1.0, -1.0, mainColor));
		addVertex(Vertex(-1.0, 0.33, -1.0, mainColor));
		addVertex(Vertex(-1.0, -0.33, -1.0, mainColor));
		addVertex(Vertex(1.0, -0.33, -1.0, mainColor));
		addVertex(Vertex(1.0, 0.33, -1.0, mainColor));
		addVertex(Vertex(-0.33, -1.0, -1.0, mainColor));
		addVertex(Vertex(0.33, -1.0, -1.0, mainColor));
		addVertex(Vertex(0.33, 1.0, -1.0, mainColor));
		addVertex(Vertex(-0.33, 1.0, -1.0, mainColor));
		addVertex(Vertex(-0.33, -0.33, -1.0, bordersColor));
		addVertex(Vertex(0.33, -0.33, -1.0, bordersColor));
		addVertex(Vertex(-0.33, 0.33, -1.0, bordersColor));
		addVertex(Vertex(0.33, 0.33, -1.0, bordersColor));
		addVertex(Vertex(-1.0, -1.0, -0.33, mainColor));
		addVertex(Vertex(1.0, -1.0, -0.33, mainColor));
		addVertex(Vertex(-1.0, 1.0, -0.33, mainColor));
		addVertex(Vertex(1.0, 1.0, -0.33, mainColor));
		addVertex(Vertex(-1.0, 0.33, -0.33, bordersColor));
		addVertex(Vertex(-1.0, -0.33, -0.33, bordersColor));
		addVertex(Vertex(1.0, -0.33, -0.33, bordersColor));
		addVertex(Vertex(1.0, 0.33, -0.33, bordersColor));
		addVertex(Vertex(-0.33, -1.0, -0.33, bordersColor));
		addVertex(Vertex(0.33, -1.0, -0.33, bordersColor));
		addVertex(Vertex(0.33, 1.0, -0.33, bordersColor));
		addVertex(Vertex(-0.33, 1.0, -0.33, bordersColor));
		addVertex(Vertex(-1.0, -1.0, 0.33, mainColor));
		addVertex(Vertex(1.0, -1.0, 0.33, mainColor));
		addVertex(Vertex(-1.0, 1.0, 0.33, mainColor));
		addVertex(Vertex(1.0, 1.0, 0.33, mainColor));
		addVertex(Vertex(-1.0, 0.33, 0.33, bordersColor));
		addVertex(Vertex(-1.0, -0.33, 0.33, bordersColor));
		addVertex(Vertex(1.0, -0.33, 0.33, bordersColor));
		addVertex(Vertex(1.0, 0.33, 0.33, bordersColor));
		addVertex(Vertex(-0.33, -1.0, 0.33, bordersColor));
		addVertex(Vertex(0.33, -1.0, 0.33, bordersColor));
		addVertex(Vertex(0.33, 1.0, 0.33, bordersColor));
		addVertex(Vertex(-0.33, 1.0, 0.33, bordersColor));
		addVertex(Vertex(-1.0, -1.0, 1.0, mainColor));
		addVertex(Vertex(1.0, -1.0, 1.0, mainColor));
		addVertex(Vertex(-1.0, 1.0, 1.0, mainColor));
		addVertex(Vertex(1.0, 1.0, 1.0, mainColor));
		addVertex(Vertex(-1.0, 0.33, 1.0, mainColor));
		addVertex(Vertex(-1.0, -0.33, 1.0, mainColor));
		addVertex(Vertex(1.0, -0.33, 1.0, mainColor));
		addVertex(Vertex(1.0, 0.33, 1.0, mainColor));
		addVertex(Vertex(-0.33, -1.0, 1.0, mainColor));
		addVertex(Vertex(0.33, -1.0, 1.0, mainColor));
		addVertex(Vertex(0.33, 1.0, 1.0, mainColor));
		addVertex(Vertex(-0.33, 1.0, 1.0, mainColor));
		addVertex(Vertex(-0.33, -0.33, 1.0, bordersColor));
		addVertex(Vertex(0.33, -0.33, 1.0, bordersColor));
		addVertex(Vertex(-0.33, 0.33, 1.0, bordersColor));
		addVertex(Vertex(0.33, 0.33, 1.0, bordersColor));
	}

	// faces.
	{
		addFace(Face(15, 10, 3));
		addFace(Face(13, 6, 1));
		addFace(Face(13, 15, 7));
		addFace(Face(5, 4, 14));
		addFace(Face(14, 15, 13));
		addFace(Face(0, 5, 12));
		addFace(Face(12, 13, 9));
		addFace(Face(4, 2, 11));
		addFace(Face(14, 11, 10));
		addFace(Face(3, 19, 23));
		addFace(Face(7, 23, 22));
		addFace(Face(3, 10, 26));
		addFace(Face(0, 16, 21));
		addFace(Face(5, 21, 20));
		addFace(Face(0, 8, 24));
		addFace(Face(2, 18, 27));
		addFace(Face(11, 27, 26));
		addFace(Face(1, 17, 25));
		addFace(Face(1, 6, 22));
		addFace(Face(9, 25, 24));
		addFace(Face(2, 4, 20));
		addFace(Face(23, 35, 34));
		addFace(Face(16, 28, 33));
		addFace(Face(21, 33, 32));
		addFace(Face(26, 38, 31));
		addFace(Face(18, 30, 39));
		addFace(Face(24, 36, 28));
		addFace(Face(17, 29, 37));
		addFace(Face(22, 34, 29));
		addFace(Face(27, 39, 38));
		addFace(Face(20, 32, 30));
		addFace(Face(25, 37, 36));
		addFace(Face(19, 31, 35));
		addFace(Face(33, 28, 40));
		addFace(Face(32, 33, 45));
		addFace(Face(38, 50, 43));
		addFace(Face(39, 30, 42));
		addFace(Face(36, 48, 40));
		addFace(Face(37, 29, 41));
		addFace(Face(34, 46, 41));
		addFace(Face(38, 39, 51));
		addFace(Face(32, 44, 42));
		addFace(Face(36, 37, 49));
		addFace(Face(35, 31, 43));
		addFace(Face(34, 35, 47));
		addFace(Face(54, 55, 53));
		addFace(Face(49, 53, 52));
		addFace(Face(45, 40, 48));
		addFace(Face(52, 54, 44));
		addFace(Face(51, 42, 44));
		addFace(Face(50, 51, 54));
		addFace(Face(43, 50, 55));
		addFace(Face(46, 47, 55));
		addFace(Face(41, 46, 53));
		addFace(Face(7, 15, 3));
		addFace(Face(9, 13, 1));
		addFace(Face(6, 13, 7));
		addFace(Face(12, 5, 14));
		addFace(Face(12, 14, 13));
		addFace(Face(8, 0, 12));
		addFace(Face(8, 12, 9));
		addFace(Face(14, 4, 11));
		addFace(Face(15, 14, 10));
		addFace(Face(7, 3, 23));
		addFace(Face(6, 7, 22));
		addFace(Face(19, 3, 26));
		addFace(Face(5, 0, 21));
		addFace(Face(4, 5, 20));
		addFace(Face(16, 0, 24));
		addFace(Face(11, 2, 27));
		addFace(Face(10, 11, 26));
		addFace(Face(9, 1, 25));
		addFace(Face(17, 1, 22));
		addFace(Face(8, 9, 24));
		addFace(Face(18, 2, 20));
		addFace(Face(22, 23, 34));
		addFace(Face(21, 16, 33));
		addFace(Face(20, 21, 32));
		addFace(Face(19, 26, 31));
		addFace(Face(27, 18, 39));
		addFace(Face(16, 24, 28));
		addFace(Face(25, 17, 37));
		addFace(Face(17, 22, 29));
		addFace(Face(26, 27, 38));
		addFace(Face(18, 20, 30));
		addFace(Face(24, 25, 36));
		addFace(Face(23, 19, 35));
		addFace(Face(45, 33, 40));
		addFace(Face(44, 32, 45));
		addFace(Face(31, 38, 43));
		addFace(Face(51, 39, 42));
		addFace(Face(28, 36, 40));
		addFace(Face(49, 37, 41));
		addFace(Face(29, 34, 41));
		addFace(Face(50, 38, 51));
		addFace(Face(30, 32, 42));
		addFace(Face(48, 36, 49));
		addFace(Face(47, 35, 43));
		addFace(Face(46, 34, 47));
		addFace(Face(52, 54, 53));
		addFace(Face(48, 49, 52));
		addFace(Face(52, 45, 48));
		addFace(Face(45, 52, 44));
		addFace(Face(54, 51, 44));
		addFace(Face(55, 50, 54));
		addFace(Face(47, 43, 55));
		addFace(Face(53, 46, 55));
		addFace(Face(49, 41, 53));
	}

	logDebug << "Strange cube init finished" << logEnd;
}


StrangeCube::~StrangeCube()
{
}