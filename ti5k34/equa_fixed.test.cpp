#include <fstream>
#include <sstream>

void setUpStreams(const std::string& input) {
    std::ofstream inFile("equa.inp");
    inFile << input;
    inFile.close();
    freopen("equa.inp", "r", stdin);
    freopen("equa.out", "w", stdout);
}

std::string getOutput() {
    std::ifstream outFile("equa.out");
    std::stringstream buffer;
    buffer << outFile.rdbuf();
    outFile.close();
    return buffer.str();
}

int main(int argc, char **argv) {
    return 0;
}
