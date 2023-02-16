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
  void quicksort(Medicine arr[], int low, int high)
  {
    if (low < high)
    {
      int pi = partition(arr, low, high);
      quicksort(arr, low, pi - 1);
      quicksort(arr, pi + 1, high);
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
      int pi = partitionByDescription(arr, low, high);
      quicksortByDescription(arr, low, pi - 1);
      quicksortByDescription(arr, pi + 1, high);
    }
  }
}