/*
The school cafeteria offers circular and square sandwiches at lunch break,
referred to by numbers 0 and 1 respectively. All students stand in a queue. 
Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. 
The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the 
stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich 
and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] 
is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the 
stack) and students[j] is the preference of the j​​​​​​th student in the initial 
queue (j = 0 is the front of the queue).
Return the number of students that are unable to eat.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i = 0 ; i < students.size(); i++){
            q.push(students[i]);
        }
        int rotations = 0 , i = 0;
        while(q.size() && rotations < q.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                rotations = 0;
            } else {
                int choice = q.front();
                q.pop();
                q.push(choice);
                rotations++;
            }
        }
        return q.size();
    }
};

/*
Runtime: 0 ms
Memory: 8.7 MB
*/
