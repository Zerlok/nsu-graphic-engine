#include <iostream>
#include <iomanip>
#include <logger.hpp>

#include "tasks/task04.hpp"
#include "tasks/task05.hpp"
#include "tasks/task06.hpp"
#include "tasks/task07.hpp"
#include "tasks/projectshadows.hpp"

#include "core/opengls.hpp"
#include "core/animation.hpp"


//logger_t globalLogging = loggerGlobal(loggerLDebug, loggerDFull);
logger_t globalLogger = loggerInit(std::cout, loggerLDebug, loggerDFull);


int main(int argc, char *argv[])
{
	TaskPtr task;

	// Choose task.
//	task = new Task04TexturesFiltering();
//	task = new Task04TexturesMixingRoad();
//	task = new Task04EarthSphereUVMapping();

//	task = new Task05NormalMappingEarth();

//	task = new Task06ObjFileImportExport();

//	task = new Task07ActionInput();

	task = new ShadowsTesting();

	task->run();

	return 0;
}
