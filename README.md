##Data Structures and Algorithms Project
This is a project that I did for my Data Structures and Algorithms class. The goal of this project was to demonstrate my understanding of the principles of the class by completing three homework assignments. The details of each homework can be seen below.
## Homework 1 Description
### Stacks, queues and the list using linked list
Write a list class to implement a doubly linked list. The list should accommodate integers and pointers. You may add other types as you need them. 

Include member functions for the following:

void 	insert_front(int data ); <br>
void 	insert_front(void *data ); <br>
void 	insert_rear(int data );<br>
void 	insert_rear(void *data );<br>
int 	remove_front_i( );<br>
void * 	remove_front_p( );<br>
int 	remove_rear_i( );<br>
void *	remove_rear_p( );<br>
int 	empty( ); <br> 

Use dynamic memory. Use the "new" instruction to allocate memory when inserting and the delete instruction to return the memory when removing. 

Make the list into a class where the actual list is private and the member functions are public. Prove your program correctness by applying several test cases. It’s up to you to decide what test cases will provide sufficient confidence your program works correctly. The output should have several test cases. Do a good job as you will use this class in the remainder of your programming assignments. 

## Homework 2 Description
### Binary search trees, AVL trees
Write a program that reads a text file and outputs a list of all words in alphabetical order. Each word should be displayed with a list of line numbers on which it occurs in the file.  Use an AVL binary search tree to store the words seen. 

Requirements:
1.	The program must work for arbitrary large files sizes. 
2.	You must test the program using the file I will provide. 
3.	Each node is to have a linked list to store all of the line numbers. Use the list you created in assignment 1. 
4.	Make the tree a class with the necessary functions. 

Example:

Input<br>
Hello Bill, <br>
Did you hear about Aunt Betty or <br>
about Aunt White? I cannot believe that <br>
…<br>

Output<br>
about		2, 3<br>
Aunt		2, 3<br>
believe		3<br>
Betty		2<br>
Bill		1<br>
cannot		3<br>
Did		    2<br>
hear		2<br>
Hello		1<br>
I		    2<br>
or		    2<br>
that		3<br>
White		3<br>
you		    2<br>
…<br>

## Homework 3 Description
### Graph and sorting algorithms
You are to write a program that finds the driving direction of a specified initial and end location much like MapQuest or Google Maps. You are to read the map information from a text file and create a graph. Each intersection and point of interest in the map will be given a unique name and be a vertex in the graph. Each road connecting 2 intersections is an edge in the graph. The edge names do not need to be unique. Use a directional graph since some streets may be one-ways. 
<br><br>The text file will look like:<br>
![Example inupt homework 3](homework_desc/HW3_example_input.PNG)
Steps:<br>
1.   Write a function to perform a Quick Sort or Merge Sort on a list of alphanumeric data. <br> 
2.   Read the text file and add each intersection name to the list. Only read the first column since all intersection names will be in there.<br>
3.   Sort the list using the Quick Sort or Merge Sort algorithm<br>
4.   Copy the names from the sorted list into the graph. Omit duplicates.<br>
5.   Create the graph by reading the original map file and adding an edge for each street. Use a binary search algorithm to find the proper vertex in the graph.<br>
6.   In the main program ask the user to input a start and end intersection.<br>
7.   Find the shortest and quickest path from the start to the end intersection. The output should indicate the name of the street and the distance.<br>
<br>The output should look like:<br>
From Alafaya&GeminiN <br> 
Take Gemini East to Gemini&GreekParkCt   .3<br>
Take Gemini East to Gemini&KnightCtE .5<br>
Take KnightCt North to Arena .1<br>