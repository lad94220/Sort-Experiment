#include "command.h"
#include "sort.h"

int main(int argc, char** argv) {
    char* input = new char[strlen("input.txt") + 1];
    strcpy(input, "input.txt");
    char* input1 = new char[strlen("input1.txt") + 1];
    strcpy(input1, "input1.txt");
    char* input2 = new char[strlen("input2.txt") + 1];
    strcpy(input2, "input2.txt");
    char* input3 = new char[strlen("input3.txt") + 1];
    strcpy(input3, "input3.txt");
    char* input4 = new char[strlen("input4.txt") + 1];
    strcpy(input4, "input4.txt");
    char* output = new char[strlen("output.txt") + 1];
    strcpy(output, "output.txt");

    if (strcmp(argv[1], "-a") == 0) { //command 1,2,3
        string output_para;
        if (argc == 5) {
            if (isNum(argv[3]) == 0) { //command 1
                output_para = argv[4];
                int n;
                int* array = readFile(argv[3], n);
                int* array1 = new int[n];
                for (int i = 0; i < n; i++) array1[i] = array[i];

                size_t count_compare = count_comparisons(array, n, argv[2]);
                double run_time = runtime(array1, n, argv[2]);

                //write sorted array
                writeFile(input, array, n);

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

                //delete array
                delete array;
                delete array1;            
            } 
            else { //command 3
                int n = stoi(argv[3]);
                output_para = argv[4];
                int* array = new int[n];
                int* array1 = new int[n];

                //console output
                cout << "ALGORITHM MODE\n";
                cout << "Algorithm: " << argv[2] << endl;
                cout << "Input size: " << n << endl;

                //randomize
                cout << "Input order: Randomize\n";
                cout << "-------------------------\n";
                GenerateData(array, n, 0);
                for (int i = 0; i < n; i++) array1[i] = array[i];

                //write randomized data
                writeFile(input1, array, n);

                if (output_para == "-both") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array1, n, argv[2]) << endl;    
                }
                if (output_para == "-time") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << endl;
                }
                if (output_para == "-comp") {
                    cout << "Running time (if required): " << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array, n, argv[2]) << endl;   
                }

                //nearly sorted 
                cout << "Input order: Nearly Sorted\n";
                cout << "-------------------------\n";
                GenerateData(array, n, 3);
                for (int i = 0; i < n; i++) array1[i] = array[i];

                //write nearly sorted data
                writeFile(input2, array, n);

                if (output_para == "-both") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array1, n, argv[2]) << endl;    
                }
                if (output_para == "-time") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << endl;
                }
                if (output_para == "-comp") {
                    cout << "Running time (if required): " << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array, n, argv[2]) << endl;
                }

                //sorted
                cout << "Input order: Sorted\n";
                cout << "-------------------------\n";
                GenerateData(array, n, 1);
                for (int i = 0; i < n; i++) array1[i] = array[i];

                //write sortd data
                writeFile(input3, array, n);

                if (output_para == "-both") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array1, n, argv[2]) << endl;    
                }
                if (output_para == "-time") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << endl;
                }
                if (output_para == "-comp") {
                    cout << "Running time (if required): " << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array, n, argv[2]) << endl;
                }

                //reversed
                cout << "Input order: Reversed\n";
                cout << "-------------------------\n";
                GenerateData(array, n, 2);
                for (int i = 0; i < n; i++) array1[i] = array[i];

                //write reversed data
                writeFile(input4, array, n);
                
                if (output_para == "-both") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array1, n, argv[2]) << endl;    
                }
                if (output_para == "-time") {
                    cout << "Running time (if required): " << runtime(array, n, argv[2]) << endl;
                    cout << "Comparisions (if required): " << endl;
                }
                if (output_para == "-comp") {
                    cout << "Running time (if required): " << endl;
                    cout << "Comparisions (if required): " << count_comparisons(array, n, argv[2]) << endl;
                }

                //delete array
                delete array;
                delete array1;
            }
        } 
        else { //command 2
            output_para = argv[5];
            int n = stoi(argv[3]);
            int* array = new int[n];
            int* array1 = new int[n];
            int data_type;
            string input_order;
            if (strcmp(argv[4], "-rand") == 0) {data_type = 0; input_order = "randomized data";}
            if (strcmp(argv[4], "-sorted") == 0) {data_type = 1; input_order = "sorted data";}
            if (strcmp(argv[4], "-rev") == 0) {data_type = 2; input_order = "reversed data";}
            if (strcmp(argv[4], "-nsorted") == 0) {data_type = 3; input_order = "nearly sorted data";}
            
            GenerateData(array, n, data_type);
            for (int i = 0; i < n; i++) array1[i] = array[i];

            //write generated array
            writeFile(input, array, n);

            size_t count_compare = count_comparisons(array1, n, argv[2]);
            double run_time = runtime(array, n, argv[2]);

            //write sorted array
            writeFile(output, array, n);

            //console output
            cout << "ALGORITHM MODE\n";
            cout << "Algorithm: " << argv[2] << endl;
            cout << "Input size: " << n << endl;
            cout << "Input order: " << input_order << endl;
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

            //delete array
            delete array;
            delete array1;
        }
    } 
    else if (strcmp(argv[1], "-c") == 0) { //command 4,5
        if (argc == 5) { //command 4
            int n;
            int* array = readFile(argv[4], n);
            int* array1 = new int[n];
            int* array2 = new int[n];
            int* array3 = new int[n];
            for (int i = 0; i < n; i++) array1[i] = array[i];
            for (int i = 0; i < n; i++) array2[i] = array[i];
            for (int i = 0; i < n; i++) array3[i] = array[i];

            //console output
            cout << "COMPARE MODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input size: " << n << endl;
            cout << "-------------------------\n";
            cout << "Running time: " << runtime(array, n, argv[2]) << " | " 
                                     << runtime(array1, n, argv[3]) << endl;
            cout << "Comparisions: " << count_comparisons(array2, n, argv[2]) << " | " 
                                     << count_comparisons(array3, n, argv[3]) << endl; 

            //delete array
            delete array;
            delete array1;
            delete array2;
            delete array3;
        }
        if (argc == 6) { //command 5
            int n = stoi(argv[4]);
            int* array = new int[n];
            int* array1 = new int[n];
            int* array2 = new int[n];
            int* array3 = new int[n];
            int data_type;
            string input_order;
            if (argv[5] == "-rand") {data_type = 0; input_order = "randomized data";}
            if (argv[5] == "-sorted") {data_type = 1; input_order = "sorted data";}
            if (argv[5] == "-rev") {data_type = 2; input_order = "reversed data";}
            if (argv[5] == "-nsorted") {data_type = 3; input_order = "nearly sorted data";}
            
            GenerateData(array, n, data_type);
            for (int i = 0; i < n; i++) array1[i] = array[i];
            for (int i = 0; i < n; i++) array2[i] = array[i];
            for (int i = 0; i < n; i++) array3[i] = array[i];

            //write generated array
            writeFile(input, array, n);

            //console output
            cout << "COMPARE MODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
            cout << "Input size: " << n << endl;
            cout << "Input order: " << input_order << endl;
            cout << "-------------------------\n";
            cout << "Running time: " << runtime(array, n, argv[2]) << " | " 
                                     << runtime(array1, n, argv[3]) << endl;
            cout << "Comparisions: " << count_comparisons(array2, n, argv[2]) << " | " 
                                     << count_comparisons(array3, n, argv[3]) << endl; 

            //delete array
            delete array;
            delete array1;
            delete array2;
            delete array3;
        }
    }
    else if (strcmp(argv[1], "-e") == 0) {
        int n = stoi(argv[2]);
        int data_type;
        string input_order = argv[3];
        int* src = new int[n];
        int* array1 = new int[n];
        int* array2 = new int[n];

        if (input_order == "-rand") data_type = 0;
        if (input_order == "-nsorted") data_type = 3;
        if (input_order == "-sorted") data_type = 1;
        if (input_order == "-rev") data_type = 2;

        GenerateData(src, n, data_type);
    
        //console output
        cout << "Runtime | Comparisions\n";
        //selection
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Selection sort: " << runtime(array1, n, "selection-sort") << " | " 
                                   << count_comparisons(array2, n, "selection-sort") << endl;
        //insertion
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Insertion sort: " << runtime(array1, n, "insertion-sort") 
                                   << " | " << count_comparisons(array2, n, "insertion-sort") << endl;
        //bubble
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Bubble sort: " << runtime(array1, n, "bubble-sort") << " | " 
                                << count_comparisons(array2, n, "bubble-sort") << endl;
        //heap
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Heap sort: " << runtime(array1, n, "heap-sort") << " | " 
                              << count_comparisons(array2, n, "heap-sort") << endl;
        //merge
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Merge sort: " << runtime(array1, n, "merge-sort") << " | " 
                               << count_comparisons(array2, n, "merge-sort") << endl;
        //quick
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Quick sort: " << runtime(array1, n, "quick-sort") << " | " 
                               << count_comparisons(array2, n, "quick-sort") << endl;
        //radix
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Radix sort: " << runtime(array1, n, "radix-sort") << " | " 
                               << count_comparisons(array2, n, "radix-sort") << endl;
        //shaker
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Shaker sort: " << runtime(array1, n, "shaker-sort") << " | " 
                                << count_comparisons(array2, n, "shaker-sort") << endl;
        //shell
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Shell sort: " << runtime(array1, n, "shell-sort") << " | " 
                               << count_comparisons(array2, n, "shell-sort") << endl;
        //counting
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Counting sort: " << runtime(array1, n, "counting-sort") << " | " 
                                  << count_comparisons(array2, n, "counting-sort") << endl;
        //flash
        for (int i = 0; i < n; i++) array1[i] = src[i];
        for (int i = 0; i < n; i++) array2[i] = src[i];
        cout << "Flash sort: " << runtime(array1, n, "flash-sort") << " | " 
                               << count_comparisons(array2, n, "flash-sort") << endl;
    }
    else { //error
        cout << "Error command!!";
    }
    return 0;
}