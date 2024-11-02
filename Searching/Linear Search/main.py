def linear_search(arr, target):
    """
    Perform a linear search on the given array to find the target element.

    :param arr: List of elements to search through.
    :param target: The element to search for.
    :return: The index of the target element if found; otherwise, -1.
    """
    for index in range(len(arr)):
        if arr[index] == target:
            return index  # Target found, return the index
    return -1  # Target not found


# Example usage:
if __name__ == "__main__":
    numbers = [5, 3, 8, 4, 2]
    target = 4

    result = linear_search(numbers, target)

    if result != -1:
        print(f"Element {target} found at index {result}.")
    else:
        print(f"Element {target} not found in the list.")
