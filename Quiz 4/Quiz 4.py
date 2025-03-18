"""Given a non-empty array of integers nums, every element appears twice except for one. Find that single one."""

def single_number(nums):
    result=0
    for num in nums:
        result ^= num #XOR operation
    return result
nums = [2,1,4,5,2,4,1]
print(single_number(nums))