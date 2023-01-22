import java.util.Scanner;

public class Algorithm {
    //    bubble sort
    public static void bubbleSort(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        System.out.println("\n-----------------Bubble sort-------------------");
        dup(arr, size);
    }

    //    selection sort
    public static void selectionSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int smallest = i;
            for (int j = i + 1; j < size; j++) {
                if (smallest > arr[j]) {
                    smallest = arr[j];
                }
            }
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
        System.out.println("\n------------Selection Sort-----------------");
        dup(arr, size);
    }

    //    insertion sort
    public static void InsertionSort(int arr[], int size){
        for(int i = 0; i<size-1; i++){
            int sorted = arr[i];
            int j= i-1;
            while(j>=0 && sorted < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = sorted;
        }
        System.out.println("\n-------------Insertion sort--------------------");
        dup(arr, size);
    }
    private static void dup(int[] arr, int size) {
        System.out.print("[");
        for (int k = 0; k < size - 1; k++) {
            System.out.print(arr[k] + ",");
        }
        System.out.print(arr[size - 1]);
        System.out.print("]");
    }

    public static void inputArray() {
        // input object
        Scanner in = new Scanner(System.in);
        // taking input for array size
        System.out.println("Please input the size of array");
        int size = in.nextInt();
        // declaring new arr
        int arr[] = new int[size];
        // taking element from user
        System.out.println("----Please input the array element of your desired-----");
        for (int i = 0; i < size; i++) {
            arr[i] = in.nextInt();
        }
        printArray(arr, size);
        bubbleSort(arr, size);
        selectionSort(arr, size);
        InsertionSort(arr, size);
    }

    public static void printArray(int[] arr, int size) {
        //        print original array
        System.out.println("--------------Original Array-------------------");
        dup(arr, size);
    }

    //    main function
    public static void main(String[] args) {
        inputArray();
    }
}
