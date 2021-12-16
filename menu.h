#ifndef MEPHI_3_LAB_1_MENU_H
#define MEPHI_3_LAB_1_MENU_H

#endif //MEPHI_3_LAB_1_MENU_H

#include "LinkedList.h"
#include "DynamicArray.h"
#include "ListSequence.h"
#include "Sort.h"

template<typename T>
void randomDataArray(T *data, int size) {
    for (int i = 0; i < size; i++) {
        int el = rand() % 100;
        data->Append(el);
    }
}

template<typename T>
void randomDataList(T *li, int size) {
    for (int i = 0; i < size; i++) {
        int el = rand() % 100;
        li->Set(el, i);
    }
}

template<typename T>
void printSequense(T *str) {
    for (int i = 0; i < str->GetSize(); i++) {
        std::cout << str->Get(i) << ' ';
    };
    std::cout << std::endl;
    return;
}


int readInt(int from = std::numeric_limits<int>::min(), int to = std::numeric_limits<int>::max()) {
    while (true) {
        try {
            std::string line;
            std::getline(std::cin, line);
            if (line.empty()) throw std::exception();

            int read = std::stoi(line);
            if (read < from || read > to) throw std::exception();

            std::cout << "\n";
            return read;
        }
        catch (...) {
            std::cout << "Please, enter a number from " << std::to_string(from) << " to " << std::to_string(to) << ": ";
        }

    }
}


void printMenu() {
    std::cout << "1. Set array sequence" << endl;
    std::cout << "2. Set list sequence" << endl;
    std::cout << "3. Select sort function" << endl;
    std::cout << "4. Compare sort functions" << endl;
    std::cout << "5. Exit" << endl;
    std::cout << "Number: ";
    return;
}


ArraySequence<int> *readArray() {
    int size;
    while (true) {
        std::cout <<"Set size: " << endl;
        std::cin >> size;
        try {
            ArraySequence<int> *da = new ArraySequence<int>(size);
            std::cout << "1. Set automatically" << endl;
            std::cout << "2. Set by hand" << endl;

            int choice = readInt(1, 2);
            switch (choice) {
                case 1:
                    randomDataArray(da, size);
                    break;
                case 2:
                    for (int i = 0; i < size; i++) {
                        int el;
                        std::cin >> el;
                        da->Append(el);
                    }
                    break;
            }
            printSequense(da);
            return da;
        }
        catch (std::exception &e) {
            std::cout << e.what() << '\n';
            return nullptr;
        }
    }
}

ListSequence<int> *readList() {
    int size;
    while (true) {
        std::cout << "Set size: " << endl;
        std::cin >> size;
        try {
            ListSequence<int> *li = new ListSequence<int>(size);
            std::cout << "1. Set automatically" << endl;
            std::cout << "2. Set by hand" << endl;

            int choice = readInt(1, 2);
            switch (choice) {
                case 1:
                    randomDataList(li, size);
                    break;
                case 2:
                    for (int i = 0; i < size; i++) {
                        int el;
                        std::cin >> el;
                        li->Set(el, i);
                    }
                    break;
            }
            printSequense(li);
            return li;
        }
        catch (std::exception &e) {
            std::cout << e.what() << '\n';
            return nullptr;
        }
    }
}

int menu() {
    ArraySequence<int> *arraySequence = nullptr;
    ListSequence<int> *listSequence = nullptr;
    float c = 0;
    while (true) {
        printMenu();

        int choice = readInt(1, 5);
        switch (choice) {
            case 1:
                delete arraySequence;
                arraySequence = readArray();
                break;
            case 2:
                delete listSequence;
                listSequence = readList();
                break;
            case 3:
                while (true) {
                    std::cout << "Choose sequence type:" << endl;
                    std::cout << "1. Array sequence." << endl;
                    std::cout << "2. List sequence." << endl;
                    std::cout << "3. Back" << endl;
                    std::cout << "Number: ";
                    int choiceSeq = readInt(1, 3);
                    if (choiceSeq == 3) break;

                    while (true) {
                        try {
                            std::cout << "\n1. Bubble sort." << endl;
                            std::cout << "2. Shaker sort." << endl;
                            std::cout << "3. Quick sort." << endl;
                            std::cout << "4. Insertion sort." << endl;
                            std::cout << "5. Shell sort." << endl;
                            std::cout << "6. Back." << endl;
                            std::cout << "Number: ";
                            int choiceSort = readInt(1, 6);
                            if (choiceSort == 6) break;


                            Sorter<int> *sorter = new Sorter<int>();


                            switch (choiceSort) {
                                case 1:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> sorted(*(arraySequence));
                                        auto point_1 = std::chrono::system_clock::now();
                                        sorter->BubbleSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto point_2 = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = point_2 - point_1;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Bubble sort time: " << elapsed_sort.count() << endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> sorted(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->BubbleSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Bubble sort time: " << elapsed_sort.count() << endl;
                                    }
                                    break;
                                case 2:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> sorted(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShakerSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Shaker sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> sorted(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShakerSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Shaker sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 3:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> sorted(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->QuickSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        }, sorted.GetSize() - 1);
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Quick sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> sorted(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->QuickSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        }, sorted.GetSize() - 1);
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Quick sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 4:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> sorted(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->InsertionSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Insertion sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> sorted(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->InsertionSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Insertion sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 5:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> sorted(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShellSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Shell sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> sorted(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShellSort(sorted, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        cout << "Sorted array:"<< sorted << endl;
                                        cout << "Shell sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                            }
                        }
                        catch (std::exception &e) {
                            std::cout << e.what() << '\n';
                            return 1;
                        }
                    }
                }
                break;

            case 4:
                while (true) {
                    std::cout << "Select sequence: " << endl;
                    std::cout << "1. Set arraySequence (array)" << endl;
                    std::cout << "2. Set listSequence (list)" << endl;
                    std::cout << "3. exit" << endl;
                    int choiceSeq = readInt(1, 3);
                    if (choiceSeq == 3) break;

                    try {

                        std::chrono::duration<double> elapsedSort1;
                        std::chrono::duration<double> elapsedSort2;

                        for (int k = 1; k < 3; k++) {
                            std::cout << "Please, select function #" << std::to_string(k) << ": " << endl;

                            std::cout << "1. bubble sort" << endl;
                            std::cout << "2. shaker sort" << endl;
                            std::cout << "3. quick sort" << endl;
                            std::cout << "4. insertion sort" << endl;
                            std::cout << "5. shell sort" << endl;
                            std::cout << "6. exit" << endl;
                            int choiceSort = readInt(1, 6);
                            if (choiceSort == 6) break;


                            Sorter<int> *sorter = new Sorter<int>();


                            switch (choiceSort) {
                                case 1:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> Asort(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->BubbleSort(Asort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Asort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> Bsort(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->BubbleSort(Bsort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Bsort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 2:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> Asort(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShakerSort(Asort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Asort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> Bsort(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShakerSort(Bsort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Bsort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 3:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> Asort(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->QuickSort(Asort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        }, Asort.GetSize() - 1);
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Asort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> Bsort(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->QuickSort(Bsort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        }, Bsort.GetSize() - 1);
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Bsort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 4:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> Asort(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->InsertionSort(Asort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Asort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> Bsort(*(listSequence));
                                        auto point_1 = std::chrono::system_clock::now();
                                        sorter->InsertionSort(Bsort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto point_2 = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = point_2 - point_1;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Bsort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                                case 5:
                                    if (choiceSeq == 1) {
                                        if (arraySequence == nullptr) arraySequence = readArray();
                                        ArraySequence<int> Asort(*(arraySequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShellSort(Asort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Asort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    } else {
                                        if (listSequence == nullptr) listSequence = readList();
                                        ListSequence<int> Bsort(*(listSequence));
                                        auto startTime = std::chrono::system_clock::now();
                                        sorter->ShellSort(Bsort, [](int a, int b) {
                                            if (a < b)
                                                return -1;
                                            if (a > b)
                                                return 1;
                                            else
                                                return 0;
                                        });
                                        auto endTime = std::chrono::system_clock::now();
                                        std::chrono::duration<double> elapsed_sort = endTime - startTime;
                                        if (k == 1) {
                                            elapsedSort1 = elapsed_sort;
                                        } else {
                                            elapsedSort2 = elapsed_sort;
                                        }
                                        printSequense(&Bsort);
                                        cout << "Sort time: " << elapsed_sort.count() << std::endl;
                                    }
                                    break;
                            }
                        }

                        if (elapsedSort1 < elapsedSort2) {
                            std::cout << "Function #1 works faster than function #2\n";
                        } else {
                            std::cout << "Function #2 works faster than function #1\n";
                        }


                    }
                    catch (std::exception &e) {
                        std::cout << e.what() << '\n';
                        return 1;
                    }

                }
                break;
            case 5:
                return 0;

        }
    }
}