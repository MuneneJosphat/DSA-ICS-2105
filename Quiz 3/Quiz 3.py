"""Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct
"""

def checkDuplicates(nums):
    unique_nums = set(nums)
    return len(unique_nums) != len(nums)

array = [1,2,3,4,5]
print(checkDuplicates(array))

array2 = [1,2,3,4,2,5]
print(checkDuplicates(array2))