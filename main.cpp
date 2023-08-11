#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Book.h"

using namespace std;

// void readFile(const string filename, vector<Book> & books){
//     Book newBook;
//     ifstream din(filename);
//     //din.open(filename.c_str());

//     if (!din.is_open()){
//         cout << "Error; file " << filename << " could not be opened\n";
//         return;
//     }

//     string year;
//     string title;
//     string lastName;
//     string firstName;
//     string genre;
//     string rating;

//     while(!din.eof()){
//         getline(din, year, ',');
//         getline(din, title, ',');
//         getline(din, lastName, ',');
//         getline(din, firstName, ',');
//         getline(din, genre, ',');
//         getline(din, rating, ',');
//         if (year == ""){
//             break;
//         }
//         int yearProduced = stoi(year);
//         float theRating = stof(rating);

//         Book newBook(yearProduced, title, lastName, firstName, genre, theRating);
//         books.push_back(newBook);
//     }
//     din.close();

// }

void readFile(const string filename, vector<Book> & books){
    //Account account; 
    //ifstream inFS(filename);     // Input file stream
    string year;
    string title;
    string lastName;
    string firstName;
    string genre;
    string rating;
    
    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return;
    }
    while(getline(din, year, ','))
    {
        getline(din, title, ',');
        getline(din, lastName, ','); 
        getline(din, firstName, ','); 
        getline(din, genre, ','); 
        getline(din, rating);
        Book temp (stoi(year),title,lastName, firstName, genre, stof(rating));
        books.push_back(temp);
    }
 
    din.close();
}

//selection sort for the year
void selection_sort(vector<Book> &books){
    int low = 0; 
    int high = books.size()-1; 
    
    for (int last = high; last > low; last--){
        int largest = low; 
        for (int j = low+1; j<=last; j++){
            if(books[j].getYear()> books[largest].getYear()){
                largest =  j; 
            }
        }
        int temp = books[last].getYear(); 
        books[last].setYear(books[largest].getYear()); 
        books[largest].setYear(temp); 
    }
}

//Insertion sort for Last Name 
void insertion_sort(vector<Book> &books){
    int low = 0; 
    int high = books.size()-1; 
    
    for (int i = low +1; i<=high; i++){
        string value = books[i].getLastName(); 
        int posn = i; 
        
        while((posn >0) && (books[posn-1].getLastName() > value)){
            books[posn].setLastName(books[posn-1].getLastName()); 
            posn--; 
        }
        books[posn].setLastName(value); 
    }
}

//Quick sort with titles 

string median3(string a, string b, string c)
{
   if (a < b)
   {
      if (a < c)
      {
         if (b < c)
            return b;
         else
            return c;
      }
      else
         return a;
   }
   else
   {
      if (a < c)
         return a;
      else
      {
         if (b < c)
            return c;
         else
            return b;
      }
   }
}
void partition(vector<Book> & data, int low, int high, int &mid)
{
#define HIGH_PIVOT

#ifdef HIGH_PIVOT
   // Use data[high] for pivot value
   string pivot = data[high].getTitle();
#endif

#ifdef LOW_PIVOT
   // Use data[low] for pivot value
   string pivot = data[low].getTitle();
   data[low].setTitle(data[high].getTitle())
   data[high].setTitle(pivot); 
#endif

#ifdef MID_PIVOT
   // Use data[mid] for pivot value
   mid = (low + high) / 2;
   string pivot = data[mid].getTitle();
   data[mid].setTitle(data[high].getTitle());
   data[high].setTitle(pivot); 
#endif

#ifdef MEDIAN_PIVOT
   // Use median for pivot value
   mid = (low + high) / 2;
   string pivot = median3(data[low].getTitle(), data[mid].getTitle(), data[high].getTitle);
   if (data[low].getTitle() == pivot)
   {
      data[low].setTitle(data[high].getTitle()); 
      data[high].setTitle(pivot); 
    }
   else if (data[mid].getTitle() == pivot)
   {
      data[mid].setTitle(data[high].getTitle());
      data[high].setTitle(pivot);
   }
#endif

   // Partition array into two parts
   int left = low;
   int right = high;
   while (left < right)
   {
      // Scan left to right
      while ((left < right) && (data[left].getTitle() < pivot)) 
         left++;

      // Scan right to left
      while ((left < right) && (data[right].getTitle() >= pivot)) 
         right--;

      // Swap data values
      string temp = data[left].getTitle();
      data[left].setTitle(data[right].getTitle()); 
      data[right].setTitle(temp); 
   }

   // Swap pivot to mid
   mid = left;
   data[high].setTitle(data[mid].getTitle()); 
   data[mid].setTitle(pivot); 
}

void quick_sort(vector<Book> &data, int low, int high){
    if(low < high){
        int mid = 0; 
        partition(data, low, high, mid); 
        
        quick_sort(data, low, mid-1); 
        quick_sort(data, mid+1, high); 
    }
}

//merge sort for first name 

void merge_sort2(vector<Book> & books, int low, int med, int high){
    vector <Book> temp; 
    int i, j; 
    i=low; 
    j = med+1; 
    
    while(i <= med && j <=high){
        if(books[i].getFirstName() <= books[j].getFirstName()){
            temp.push_back(books[i]); 
            i++; 
        }
        else{
            temp.push_back(books[j]); 
            j++;
        }
    }
    
    while(i <= med){
        temp.push_back(books[i]); 
        i++;
    }
    
    while(j <=high){
        temp.push_back(books[j]); 
        j++; 
    }
    
    for(int i =low; i <= high; i++){
        books[i].setFirstName(temp[i-low].getFirstName()); 
    }
}

void MergeSort(vector<Book> & books, int low, int high){
    if (low < high){
        int m = (low + high)/2; 
        MergeSort(books, low, m); 
        MergeSort(books, m+1, high); 
        merge_sort2(books, low, m, high); 
    }
}

// void merge_sort2(vector<Book>books, vector<Book>copy, int low, int high){
//     int range = high - low +1; 
//     if(range > 1){
//         int mid = (low+high)/2; 
//         merge_sort2(books, copy, low, mid); 
//         merge_sort2(books, copy, mid+1, high); 
        
//         int index1= low; 
//         int index2= mid+1; 
//         int index = 0; 
//          while(index1 <=mid && index2 <=high){
//              if (books[index1].getFirstName() < books[index2].getFirstName()){
//                  copy[index++].setFirstName(books[index1++].getFirstName()); 
//              }
//              else{
//                  copy[index++].setFirstName(books[index2++].getFirstName()); 
//              }
             
//          }
         
//          while(index1 <= mid){
//              copy[index++].setFirstName(books[index1++].getFirstName()); 
             
//          }
         
//          while(index2 <=high){
//              copy[index++].setFirstName(books[index2].getFirstName()); 
//          }
         
//          for(index = 0; index <range; index++){
//              books[low+index].setFirstName(copy[index].getFirstName()); 
//          }
//     }
    
// }

//void merge_sort(vector<Book> & data, int low, int high){
//     int range = high - low +1; 
//     if (range > 1)
//   {
//       // Allocate memory and call merge_sort2
//       Book *copy = new vector<Book>books;
//       merge_sort2(data, copy, low, high);
//       delete[]copy;
//   }
    
//}

//write file method 
void writeFile(const string filename, vector<Book>books){
    ofstream dout; 
    dout.open(filename.c_str()); 
    
    if(dout.fail()){
        cout << "Error; file "<< filename << " could not be opened" << endl; 
        return; 
    }
    
    for (int i = 0; i < books.size(); i++){
        dout << books[i].getYear() << ','
        << books[i].getTitle() << ','
        << books[i].getLastName() << ','
        <<books[i].getFirstName() << ','
        << books[i].getGenre() << ','
        <<books[i].getRating() << endl; 
    }
    dout.close(); 
}

int main() {
    vector<Book> books;
    readFile("books.txt", books);
    int userInput; 
    cout << "Which sorting method would you like to use? " << endl; 
    cout << "1. Selection Sort to sort year " << endl; 
    cout << "2. Insertion Sort to sort last name "<< endl; 
    cout << "3. Quick sort to sort title " << endl; 
    cout << "4. Merge sort to sort first name "<< endl; 
    cin >> userInput; 
    
    clock_t start = clock();

    switch (userInput){
        case 1: 
            //clock_t start = clock();
            selection_sort(books); 
            //clock_t end = clock();
            //double runtime = (end - start) / double(CLOCKS_PER_SEC);
            //cout << "Run time for x algorithm: " << runtime << " seconds" << endl;
            break; 
        case 2: 
            //clock_t start = clock();
            insertion_sort(books); 
            //clock_t end = clock();
            //double runtime = (end - start) / double(CLOCKS_PER_SEC);
            //cout << "Run time for x algorithm: " << runtime << " seconds" << endl;
            break; 
        case 3: 
            //clock_t start = clock();
            quick_sort(books, 0, books.size()-1); 
            //clock_t end = clock();
            //double runtime = (end - start) / double(CLOCKS_PER_SEC);
            //cout << "Run time for x algorithm: " << runtime << " seconds" << endl;
            break; 
        case 4: 
            //clock_t start = clock();
            MergeSort(books, 0, books.size()-1); 
            //clock_t end = clock();
            //double runtime = (end - start) / double(CLOCKS_PER_SEC);
            //cout << "Run time for x algorithm: " << runtime << " seconds" << endl;
            break; 
        default: cout << "This is not an option! " << endl; return 0; 
    }
    //clock_t start = clock();
    
    // calls to sorting algorithm method
    //selection_sort(books); 
    //insertion_sort(books); 
    
    //quick_sort(books, 0, books.size()-1);
    //MergeSort(books, 0, books.size()-1); 
    
    
    clock_t end = clock();
    double runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for x algorithm: " << runtime << " seconds" << endl;
    

    // for (int i = 0; i< books.size(); i++){
    //     books[i].print(); 
    // }
    
    switch (userInput){
        case 1: writeFile("selectionsorttest.csv", books); break; 
        case 2: writeFile("insertionsorttest.csv", books); break; 
        case 3: writeFile("quicksorttest.csv", books); break; 
        case 4: writeFile("mergesorttest.csv", books); break; 
    }
    //writeFile("test.csv", books); 
     
    
    return 0;
}
