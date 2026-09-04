#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

TEST_CASE("Program prints Hello, Pextra Academy!") {
    // Run the program and capture its output
    FILE* pipe = popen("build/main", "r"); // Ensure executable is 'main'
    REQUIRE(pipe != nullptr);

    char buffer[128];
    std::string output;

    while (fgets(buffer, sizeof(buffer), pipe)) {
        output += buffer;
    }

    pclose(pipe);

    REQUIRE(output == "Hello, Pextra Academy!\n");
}
