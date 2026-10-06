# Graph Coloring Using Backtracking

## Aim

To implement the Graph Coloring problem using the Backtracking technique and assign colors to all vertices of a graph such that no two adjacent vertices have the same color.

## Problem Statement

Given a graph with `N` vertices and a maximum of `M` colors, assign a color to every vertex such that two adjacent vertices do not have the same color.

The problem can be solved using the **Backtracking technique** by trying different colors for each vertex and undoing a color assignment whenever it leads to an invalid solution.

## Case Study

### Exam Hall / Classroom Scheduling

Consider a college where several subjects need to be scheduled into different time slots.

Each subject is represented as a vertex in a graph.

If two subjects have students in common, they cannot be scheduled at the same time. Therefore, an edge is placed between those subjects.

Each color represents a different time slot.

The objective is to assign time slots to all subjects such that connected subjects do not receive the same time slot.

This is a practical application of the **Graph Coloring problem**.

## Example

Consider the following graph with 4 vertices:

```text
0 ----- 1
|       |
|       |
2 ----- 3
```

Suppose we have 3 available colors:

```text
Color 1
Color 2
Color 3
```

One valid coloring is:

```text
Vertex 0 → Color 1
Vertex 1 → Color 2
Vertex 2 → Color 2
Vertex 3 → Color 1
```

Therefore, the solution vector is:

```text
1 2 2 1
```

No two adjacent vertices have the same color.

## Backtracking Approach

The algorithm assigns colors to vertices one by one.

For every vertex:

1. Try the first available color.
2. Check whether the color is safe.
3. If the color is safe, assign it to the vertex.
4. Move to the next vertex.
5. If no color can be assigned, remove the previous color assignment.
6. Try another color.
7. Continue until all vertices are colored.

The process of removing an incorrect color assignment is called **backtracking**.

## Algorithm

1. Read the number of vertices `N`.
2. Read the number of available colors `M`.
3. Read the adjacency matrix of the graph.
4. Create a solution vector and initialize all colors to `0`.
5. Start coloring from vertex `0`.
6. Try every color from `1` to `M`.
7. Check whether the selected color is safe:
   - For every adjacent vertex, check whether it already has the same color.
8. If the color is safe:
   - Assign the color to the vertex.
   - Recursively color the next vertex.
9. If the recursive call fails:
   - Remove the color.
   - Try another color.
10. If all vertices are colored, a valid solution is found.
11. Display the solution vector.

## Safe Color Condition

A color can be assigned to a vertex if no adjacent vertex has already been assigned the same color.

```text
If graph[vertex][i] == 1
and color[i] == selectedColor

Then the selected color is not safe.
```

## Solution Vector

The solution vector stores the color assigned to every vertex.

For example:

```text
Solution Vector:
1 2 2 1
```

This means:

```text
Vertex 0 → Color 1
Vertex 1 → Color 2
Vertex 2 → Color 2
Vertex 3 → Color 1
```

## Program

The implementation is provided in `Graph_Coloring.cpp`.

## Sample Input

```text
4
3
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

Where:

- `4` = number of vertices
- `3` = number of available colors
- The remaining values represent the adjacency matrix.

## Sample Output

```text
Graph Coloring Solution:

Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 2
Vertex 3 -> Color 1

Solution Vector:
1 2 2 1

Solution found successfully.
```

## Complexity Analysis

Let:

- `N` = number of vertices
- `M` = number of colors

### Time Complexity

For every vertex, up to `M` colors may be tried.

In the worst case:

**O(M^N)**

Checking whether a color is safe requires examining up to `N` vertices, so the practical worst-case complexity can be considered:

**O(N × M^N)**

### Space Complexity

The adjacency matrix requires:

**O(N²)**

The solution vector and recursion stack require:

**O(N)**

Therefore, the overall space complexity is:

**O(N²)**

## Why Backtracking Works

Graph Coloring is a constraint satisfaction problem.

Whenever a selected color violates the graph constraints, the algorithm goes back to the previous vertex and tries another color.

Thus, backtracking avoids continuing with an invalid partial coloring.

## Applications

Graph Coloring is used in:

- Exam timetable scheduling
- Register allocation in compilers
- Frequency assignment
- Map coloring
- Wireless channel assignment
- Task scheduling
- Network resource allocation

## Technologies Used

- C++
- Data Structures and Algorithms
- Backtracking
- Graph Theory
- Recursion

## Key Concepts

- Graph Coloring
- Backtracking
- Recursion
- Adjacency Matrix
- Constraint Satisfaction
- Solution Vector
- Graph Theory
- Time and Space Complexity

## Result

The Graph Coloring problem was successfully implemented using the Backtracking technique. The algorithm assigns colors to the vertices while ensuring that no two adjacent vertices have the same color and displays the resulting solution vector.
