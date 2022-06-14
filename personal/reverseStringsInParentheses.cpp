string reverseInParentheses(string s) {
    stack<string> stringStack;
    stringStack.push({});
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stringStack.push({});
        }
        else if (s[i] == ')') {
            string topString = stringStack.top();
            reverse(topString.begin(), topString.end());
            stringStack.pop();
            if (stringStack.empty()) {
                stringStack.push(topString);
            }
            else {
                stringStack.top() += topString;
            }
        }
        else {
            stringStack.top() += s[i];
        }
        
    }
    return stringStack.top();
}
