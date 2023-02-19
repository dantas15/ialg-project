namespace Search
{
  int binarySearchById(Medicine arr[], int size, long idToSearch)
  {
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (arr[mid].id == idToSearch)
      {
        return mid;
      }
      else if (arr[mid].id < idToSearch)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    // If the id is not found, return -1.
    return -1;
  };
}