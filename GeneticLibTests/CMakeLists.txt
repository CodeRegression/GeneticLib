#--------------------------------------------------------
# CMake for generating GeneticLibLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2022-02-07
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup base directory
if (WIN32)
    set(LIBRARY_BASE "D:/Work/Infrastructure/LIBS")
else()
    set(LIBRARY_BASE $ENV{HOME}/Libraries)
endif()

# Add include directory
include_directories( "../" )

# Add the NVLib library to the folder
add_library(NVLib STATIC IMPORTED)
set_target_properties(NVLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/NVLib/build/NVLib/libNVLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/NVLib"
)

# Add OpenCV to the solution
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Add the UnitTestLib library to the folder
add_library(UnitTestLib STATIC IMPORTED)
set_target_properties(UnitTestLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/UnitTestLib/build/UnitTestLib/libUnitTestLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/UnitTestLib"
)

# Create the executable
add_executable (GeneticLibTests
	Tests/CandidateSelector_Tests.cpp
	Tests/GeneticRunner_Tests.cpp
	Tests/BooleanStatement_Tests.cpp
	Tests/DecisionNode_Tests.cpp
	Tests/CodeTree_Tests.cpp
	Tests/CodeTreeFactory_Tests.cpp
	Tests/BreadthIterator_Tests.cpp
	Tests/Breed_Tests.cpp
	Tests/Mutator_Tests.cpp
	Tests/Memory_Tests.cpp
)



target_link_libraries(GeneticLibTests NVLib ${OpenCV_LIBS} GeneticLib UnitTestLib GTest::Main uuid)

# Find the associated unit tests
gtest_discover_tests(GeneticLibTests)