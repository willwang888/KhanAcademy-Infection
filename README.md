# KhanAcademy-Infection
Total and Limited Infection algorithm for Khan Academy Internship

Hey there! Thanks for taking a look at my KhanAcademy take-home project!

The instructions are as follows:

# Total Infection
When rolling out big new features, we like to enable them slowly, starting with just the core team, then a handful of users, then some more users, and so on, until we’ve ramped up to 100%. This insulates the majority of users from bad bugs that crop up early in the life of a feature.

This strategy can cause problems somewhat unique to our user base. It’s not uncommon for a classroom of students to be using the site together, so it would be confusing to show half of them a completely different version of the site. Children are not software engineers and often have a poor understanding of deployment and a/b testing, so inconsistent colors, layout, and interactions effectively mean the site is broken.

Ideally we would like every user in any given classroom to be using the same version of the site. Enter “infections”. We can use the heuristic that each teacher-student pair should be on the same version of the site. So if A coaches B and we want to give A a new feature, then B should also get the new feature. Note that infections are transitive - if B coaches C, then C should get the new feature as well. Also, infections are transferred by both the “coaches” and “is coached by” relations.
First, model users (one attribute of a user is the version of the site they see) and the coaching relations between them. A user can coach any number of other users. You don’t need to worry about handling self-coaching relationships.

Now implement the infection algorithm. Starting from any given user, the entire connected component of the coaching graph containing that user should become infected.

# Limited Infection
The problem with infection is lack of control over the number of users that eventually become infected. Starting an infection could cause only that person to become infected or at the opposite (unrealistic) extreme it could cause all users to become infected.

We would like to be able to infect close to a given number of users. Ideally we’d like a coach and all of their students to either have a feature or not. However, that might not always be possible.
Implement a procedure for limited infection. You will not be penalized for interpreting the specification as you see fit. There are many design choices and tradeoffs, so be prepared to justify your decisions.

# About My Solution
I had about 12 hours to come up with these schemas, and I definitely spent a good chunk of my time deciding how to approach it. I had to submit my solutions unfinished because I had to finish a Data Structures assignment that I have to do(this semester has definitely been an extremely hectic one), but I definitely know how to optimize it and complete it when I have time. I can explain my thinking in its entirety at a later date, because I know that my README won't do a proper job conveying all my thoughts.

So, let's dive right into it!

My solutions thus far are as follows:

  **Total Infection**: Breadth First Search through the entire connected graph starting from an inputted userID. If the user does not have the version specified, update the version to the new version. My main function tests my total infection as of now, and I have yet to test my Limited Infection Part 1, explained below. To run, type "g++ -g -Wall User.cpp graph.cpp -o test". To run, type ./test.

  *Both my limited infection algorithms act on the assumption that the specific disjoint graphs of teachers and students are given*

  **Limited Infection Part 1**: This part of my solution gives each node, or User, a weight based on how much time they have spent in total on the site. My algorithm goes through the vector of disjoint graphs, represented by userIDs, and sorts them from most time spent on the site to least time spent on the site. Then, it goes through the two dimensional array of vectors and infects the number of people that has been specified.

  Note: This algorithm does not account for teacher and student combinations having the same version. For this part, I assumed that the specific version would be sent out to users via a beta, so that users could test the beta themselves, and have their own beta version of the site — similar to the Apple Beta Program, where Apple gives new software betas to certain users who are registered for the program.

  **Limited Infection Part 2**: This part of my solution is the more logical and "intuitive" way of solving the problem at hand. It will take the number of disjoint graphs and compute their sizes. Then, my algorithm imposes a "bottom up" method of approximation to how many users out of the target can be infected, so that all of the graphs that are infected are COMPLETELY infected (teachers and students have the same version). However, I ran out of time to complete this part of my algorithm, so I left it as only being able to spit out what the total number of users that can be infected.

  Note: "limitedInfectionAndTest.cpp" has the function and the tests for Part 2. Run it by typing "g++ -g -Wall limitedInfectionAndTest.cpp -o limitedApproxTest". To run, type ./limitedApproxTest.

# Improvements

  There are many improvements I can make to both complete and refine my algorithms.

  1. Some of the implementation in my algorithms I brute forced as I was running out of time; for example, one of the operations being performed on a list of users takes O(n^2)time, and can be written in at least O(n), had I been able to put more time into it.

  2. For Limited Infection Part 2, I can have the output be *which* graphs are infected that make the number of users closest to the target, and not *how many* users can be infected. That can be done in one of the following ways: putting another layer on top of the matrix to store the graphs that were used to calculate the sum, creating a struct to pass into each instance of the matrix so that it may store which graphs were used in the calculation, or passing the values of *which* graphs AND the size of the graphs in as std::pairs into the function, so that I can take the specific graph names from the respective pairs.

  3. For Limited Infection Part 1, I can incorporate the approximation algorithm used in Part 2 to combine the calculation of the weights to number of graphs that can be completely infected. To explain, after sorting the weights of the graphs, as I am going through the 2D array to infect the Users from greatest to least weight, I can calculate what the possible number combinations are from the current sum total that I am on to find as close to the target weight as possible. This can also be done in a bottom up manner, but can also be done with Depth First Search, Djikstra's Algorithm, or even Breadth First Search to find the shortest path. I can definitely explain more about this later!

  4. FOR TESTING, I wasn't able to write out extensive tests for my functions, as I spent a lot of my time thinking about the best way to approach my solutions. I can definitely expand on this more later as well!

  5. I also wanted to implement a SQL server to populate my graphs automatically, so that is something I can incorporate in the future.
