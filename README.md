# PathFinding-Introduction-to-Programing-Project
<h2>File Handling Project Through C++</h2>

  In this assignment, a file named output.txt will be produced by reading the information in the input.txt file located in the same directory as the application. The application will not receive any information through the console interface. After it is opened, it should read the input.txt file in the folder it is in and write the result to output.txt.
  
  A graph definition is given in the “input.txt” file. In this graph definition, nodes are expressed as a pair of uppercase letters and numbers. (Ex: A1,A2,B1,B2,B3) If the letter is the type of the node, the digit indicates the same type. Paths (transitions) in the graph are written as pairs of nodes. (Ex: A1->A2 , A1->B1, A2->B1 , B1->B2, B1->B3, B1>A1, B3->A1) These data define the graph. The visual version of the graph will be as follows.
  
  ![Path](https://user-images.githubusercontent.com/83426745/215759267-0edb71cf-9ff0-462d-903a-72216af9eeb6.png)
  
  The lines at the end of the file will contain the word for the paths traversed on this graph.
  Ex: AAB , ABB, ABBAAB
  
  By determining whether each desired path definition is a path that can be followed on the graph, path and [YES] , [NO] will be written next to it in the output.txt file. There may be circular paths within the file, that is, transitions from A1 to B1 and from B1 to A1. In this case, your algorithm should be able to scan paths without going into an infinite loop. The path definition can be searched by starting from any node.
  
  Below are sample input.txt and output.txt file contents.
  
  <h3>Example 1</h3>
  
  <h4>Content of input.txt</h4>
  
A1,A2,B1,B2,B3\
Links:\
A1->A2\
A1->B1\
A2->B1\
B1->B2\
B1->B3\
B1->A1\
B3->A1\
Paths:\
AAB\
ABB\
ABBAAB

  <h4>Content of output.txt </h4>

AAB [YES]\
ABB [YES]\
ABBAAB [YES]

 <h3> Example 2</h3>
  
  <h4>Content of input.txt</h4>

A1,B1,C1,D1,D2,E1\
Links:\
A1->C1\
C1->B1\
D1->C1\
D1->D2\
D1->E1\
D2->E1\
E1->C1\
Paths:\
CBA\
CB\
ACB\
DEC\
CDE\
DDEC

 <h4> Content of output.txt:</h4>
  
CBA [NO]\
CB [YES]\
ACB [YES]\
DEC [YES]\
CDE [NO]\
DDEC [YES]





