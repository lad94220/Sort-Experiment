#include "command.h"
#include "sort.h"

int main(int argc, char** argv) {
    
    if (strcmp(argv[1], "-a") == 0) { //command 1,2,3
        string output_para;
        if (argc == 5) {
            if (isNum(argv[3]) == 0) { //command 1
                output_para = argv[4];
                int n;
                int* array = readFile(argv[3], n);

                int count_compare = count_comparisons(array, n, argv[2]);
                long long run_time = runtime(array, n, argv[2]);

                //console output
                cout << "ALGORITHM MODE\n";
                cout << "Algorithm: " << argv[2] << endl;
                cout << "Input file: " << argv[3] << endl;
                cout << "Input size: " << n << endl;
                cout << "-------------------------\n";
                if (output_para == "-both") {
                    cout << "Running time (if required): " << run_time << endl;
                    cout << "Comparisions (if required): " << count_compare << endl;    
                }
                if (output_para == "-time") {
                    cout << "Running time (if required): " << run_time << endl;
                    cout << "Comparisions (if required): " << endl;
                }
                if (output_para == "-comp") {
                    cout << "Running time (if required): " << endl;
                    cout << "Comparisions (if required): " << count_compare << endl;   
                }            
            } 
            else { //command 3
                int inputSize = stoi(argv[2]);
                output_para = argv[4];
                
            }
        } 
        else { //command 2
            output_para = argv[5];

        }

    } 
    else if (strcmp(argv[1], "-c") == 0) { //command 4,5

    } 
    else {

    }

    return 0;
}