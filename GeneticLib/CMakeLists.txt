#--------------------------------------------------------
# CMake for generating the GeneticLib
#
# @author: Wild Boar
#
# Date Created: 2022-02-07
#--------------------------------------------------------

# Setup base directory
if (WIN32)
    set(LIBRARY_BASE "D:/Work/Infrastructure/LIBS")
else()
    set(LIBRARY_BASE $ENV{HOME}/Libraries)
endif()

# Add the NVLib library to the folder
add_library(NVLib STATIC IMPORTED)
set_target_properties(NVLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/NVLib/build/NVLib/libNVLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/NVLib"
)

# Add OpenCV to the solution
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Create Library
add_library (GeneticLib STATIC
	Utility/CandidateFactoryBase.cpp
	Utility/CandidateSelector.cpp
	Utility/GeneticRunner.cpp
	Grammar/LiteralNode.cpp
	Grammar/Comparison.cpp
	Grammar/BooleanStatement.cpp
	Grammar/DecisionNode.cpp
	Grammar/CodeTree.cpp
	Grammar/CodeTreeFactory.cpp
	Grammar/BreadthIterator.cpp
	Grammar/Mutator.cpp
)

# Add link libraries
target_link_libraries(GeneticLib NVLib ${OpenCV_LIBS})