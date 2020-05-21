#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main() {
    int result = Catch::Session().run();
    return result;
}
