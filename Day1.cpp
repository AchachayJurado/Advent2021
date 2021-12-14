/******************************************************************************
 *  Day 1 .- Sonar Sweep
*******************************************************************************/

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // read measures from .txt file
    std::ifstream file ("measures.txt");
    std::vector<int> measurements;
    
    while (file.eof() == false)
    {
        int next;
        file >> next;
        measurements.push_back(next);
    }
    file.close();
    
    //calculate if the distance increases
    int increases = 0;
    for (std::size_t i=1; i<measurements.size(); i++)
    {
        if (measurements[i] > measurements[i-1])
        ++increases;
    }
    std::cout << "Number of increases: "<< increases << std::endl;
    
    //calculate if delta distance increases every 3 measurements
    increases = 0;
    std::vector<int> windows;
    for (std::size_t i=2; i < measurements.size(); ++i)
    {
        windows.push_back(measurements[i]+measurements[i-1]+measurements[i-2]);
    }
    for (std::size_t i = 1; i < windows.size(); ++i)
    {
        if (windows[i] > windows[i-1])
        ++increases;
    }
    std::cout << "Number of increases: "<< increases << std::endl;
    
    system("PAUSE");
    return 0;
}