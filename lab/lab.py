"""Task One (1)
Define two functions: summation and maximum both of which take an integer array of length
0<= n<= ∞. The summation function gets the sum of the integers while the maximum function
obtains the largest integer in the array.
Within the main function; declare an array of length n, obtain the n from the user, then allow the
user to enter these n integers storing them in the array. Call the two functions in turns and display
their outputs."""


def summation(arr):
    return sum(arr)


def maximum(arr):
    return max(arr)


def main():
    # Obtain the length of the array from the user
    n = int(input("Enter the number of integers (n): "))

    # Initialize an empty array
    arr = []

    # Allow the user to enter n integers
    for i in range(n):
        num = int(input(f"Enter integer {i + 1}: "))
        arr.append(num)

    # Call the summation function and display the result
    sum_result = summation(arr)
    print(f"The sum of the integers is: {sum_result}")

    # Call the maximum function and display the result
    max_result = maximum(arr)
    print(f"The largest integer in the array is: {max_result}")


# Run the main function
if __name__ == '__main__':
    main()