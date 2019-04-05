
// Problem 3 - Sort ( Knowledge Base: Algorithms )

// This function takes in an array of unsorted ints and sorts it
// intArray - The array of floats to have sorted
// count - The number of elements in the array

void SortIntArray( int * intArray, int count )
{
	if (intArray) {
		for (auto j = 1; j < count; j++) {
			auto key = intArray[j];
			auto i = j - 1;
			while (i >= 0 && intArray[i] > key) {
				intArray[i + 1] = intArray[i];
				i--;
			}
			intArray[i + 1] = key;
		}
	}
}
