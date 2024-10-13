#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

string YesOrNo(int n, int a[]) {
    if (n == 1) {
        return "No";
    }
    int sum1, sum2, count1, count2, allsum, medium;
    int arr1[n];
    int arr2[n];
    count1 = 0;
    count2 = 0;
    sum1 = 0;
    sum2 = 0;
    allsum = 0;
    for (int i = 0; i < n; i++) {
        allsum  += a[i];
    }
    medium = allsum / 2;
    for (int i = n - 1; i >= 0; i--) {
        if ((sum1 + a[i]) <= medium) {
            sum1 += a[i];
            arr1[count1] = a[i];
            count1++;
        } else {
            sum2 += a[i];
            arr2[count2] = a[i];
            count2++;
        }
    }
    if (sum1 == sum2) {
        stringstream ss;
        ss << "Yes" << endl;
        ss << count1 << endl;
        for (int i = 0; i < count1; i++) {
            ss << arr1[i] << " ";
        }
        ss << endl;
        ss << count2 << endl;
        for (int i = 0; i < count2; i++) {
            ss << arr2[i] << " ";
        }
        return ss.str();
    }
    return "No";
}

void run_test(int test_case_number, int input[], int n, string expected_output) {
    string result = YesOrNo(n, input);
    if (result == expected_output) {
        cout << "Test case " << test_case_number << " passed." << endl;
    } else {
        cout << "Test case " << test_case_number << " failed. Expected: " << expected_output << ", but got: " << result << endl;
    }
}

void run_all_tests() {
    int test1[] = {5};
    run_test(1, test1, 1, "No");

    int test2[] = {5, 5, 1};
    run_test(2, test2, 3, "No");

    int test3[] = {3, 8};
    run_test(3, test3, 2, "No");

    int test4[] = {2, 2, 2};
    run_test(4, test4, 3, "No");

    int test5[] = {1, 2, 3, 1};
    run_test(5, test5, 4, "No");

    int test6[] = {1, 2, 3, 4, 1};
    run_test(6, test6, 5, "No");

    int test7[] = {100000000, 1, 1, 1};
    run_test(7, test7, 4, "No");

    int test8[] = {1, 3, 2, 4, 5};
    run_test(8, test8, 5, "No");

    int test9[] = {5, 5, 5, 5, 1};
    run_test(9, test9, 5, "No");

    int test10[] = {100, 1, 1};
    run_test(10, test10, 3, "No");
}

int main() {
    run_all_tests();
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin  >> a[i];
    }
    bubbleSort(a, n);
    cout << YesOrNo(n, a)  << endl;
    return 0;
}
