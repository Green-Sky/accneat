cmake_minimum_required(VERSION 3.0)

project(accneat C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

add_library(accneat
	./src/util/map.h
	./src/util/organismsbuffer.h
	./src/util/resource.h
	./src/util/rng.h
	./src/util/std.h
	./src/util/std.hxx # TODO: delete
	./src/util/stats.h
	./src/util/timer.h
	./src/util/util.h

	./src/util/map.cpp
	./src/util/resource.cpp
	./src/util/rng.cpp
	./src/util/timer.cpp
	./src/util/util.cpp

	##########################

	./src/innovgenome/innovation.h
	./src/innovgenome/innovgenome.h
	./src/innovgenome/innovgenomemanager.h
	./src/innovgenome/innovlinkgene.h
	./src/innovgenome/innovnodegene.h
	./src/innovgenome/innovnodelookup.h
	./src/innovgenome/protoinnovlinkgene.h
	./src/innovgenome/recurrencychecker.h
	./src/innovgenome/trait.h

	./src/innovgenome/innovation.cpp
	./src/innovgenome/innovgenome.cpp
	./src/innovgenome/innovgenomemanager.cpp
	./src/innovgenome/innovlinkgene.cpp
	./src/innovgenome/innovnodegene.cpp
	./src/innovgenome/trait.cpp

	##########################

	./src/network/network.h
	./src/network/networkexecutor.h

	./src/network/cpu/cpunetwork.h
	./src/network/cpu/cpunetworkexecutor.h

	./src/network/cpu/cpunetwork.cpp

	##########################

	./src/species/species.h
	./src/species/speciesorganism.h
	./src/species/speciespopulation.h

	./src/species/species.cpp
	./src/species/speciesorganism.cpp
	./src/species/speciespopulation.cpp

	##########################

	./src/genome.h
	./src/genomemanager.h
	./src/neat.h
	./src/neattypes.h
	./src/organism.h
	./src/population.h

	./src/genomemanager.cpp
	./src/neat.cpp
	./src/organism.cpp
	./src/population.cpp
)

target_compile_features(accneat PUBLIC cxx_std_11)

target_include_directories(accneat PUBLIC "src")
target_include_directories(accneat PUBLIC "src/util")
target_include_directories(accneat PUBLIC "src/network")
target_include_directories(accneat PUBLIC "src/network/cpu")
target_include_directories(accneat PUBLIC "src/innovgenome")
target_include_directories(accneat PUBLIC "src/species")

add_executable(neat_experiments
	./src/experiments/evaluatorexperiment.h
	./src/experiments/experiment.h
	./src/experiments/experiment.cpp

	./src/experiments/maze/mazeevaluator.h
	./src/experiments/maze/maze.cpp
	./src/experiments/maze/mazeevaluator.cxx

	./src/experiments/static/staticevaluator.h
	./src/experiments/static/staticexperiment.h
	./src/experiments/static/cfg.cpp
	./src/experiments/static/regex.cpp
	./src/experiments/static/sequence.cpp
	./src/experiments/static/staticevaluator.cxx
	./src/experiments/static/xor.cpp

	./src/main.cpp
)

target_include_directories(neat_experiments PUBLIC "src/experiments")

target_link_libraries(neat_experiments PUBLIC
	accneat
)

