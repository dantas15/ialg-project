namespace Binary
{
  const string BINARY_FILENAME = "medicines.bin";

  // Use it on import .csv only
  void writeMedicines(Medicine medicines[], int size)
  {
    ofstream outfile("medicines.bin", ios::binary | ios::out | ios::trunc);
    if (outfile.is_open())
    {
      outfile.seekp(0, ios::beg);
      outfile.write(reinterpret_cast<char *>(medicines), sizeof(Medicine) * size);
      outfile.close();
    }
    else
    {
      cerr << "Erro: Não foi possível abrir o arquivo binário para escrita." << endl;
    }
  };

  size_t getMedicineFileSize(ifstream &file, int &numberOfElements)
  {
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    size_t elementSize = sizeof(Medicine);

    numberOfElements = fileSize / elementSize;

    return fileSize;
  }

  void displayMedicines()
  {
    ifstream binfile("medicines.bin", ios::in | ios::binary);
    if (binfile.is_open())
    {
      // getting the filesize
      int numberOfMedicines;
      size_t fileSize = getMedicineFileSize(binfile, numberOfMedicines);
      Medicine medicinesRead[numberOfMedicines];

      binfile.seekg(0, ios::beg);

      binfile.read(reinterpret_cast<char *>(&medicinesRead), fileSize);
      binfile.close();

      for (int i = 0; i < numberOfMedicines; i++)
      {
        cout << medicinesRead[i].id << " " << medicinesRead[i].value << " " << medicinesRead[i].pricesAreTheSame << " " << medicinesRead[i].description << " " << medicinesRead[i].marketPrice << endl;
      }
    }
    else
    {
      cerr << "Erro: Não foi possível abrir o arquivo binário para leitura." << endl;
    }
  };
}