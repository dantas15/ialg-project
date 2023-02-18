namespace Sort
{
  // Partition function for default quicksort (for medicine identification)
  int partition(Medicine arr[], int low, int high)
  {
    long pivot = arr[high].id;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
      if (arr[j].id < pivot)
      {
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
  }

  // Default quicksort function (for medicine identification)
  void quicksortById(Medicine arr[], int low, int high)
  {
    if (low < high)
    {
      int pi = partition(arr, low, high);
      quicksortById(arr, low, pi - 1);
      quicksortById(arr, pi + 1, high);
    }
  }

  // Partition function for quicksort by description
  int partitionByDescription(Medicine arr[], int low, int high)
  {
    Medicine pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
      if (strcmp(arr[j].description, pivot.description) < 0)
      {
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
  }

  // Quicksort function
  void quicksortByDescription(Medicine arr[], int low, int high)
  {
    if (low < high)
    {
      int pivot = partitionByDescription(arr, low, high);
      quicksortByDescription(arr, low, pivot - 1);
      quicksortByDescription(arr, pivot + 1, high);
    }
  }
}