/*
Cracking the Coding Interview Question 1.1 Is Unique

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
*/

var assert = require('chai').assert;

function isUnique(str) {
  let charSet = new Set();

  for (let char of str) {
    if (charSet.has(char)) {
      return false;
    }
    charSet.add(char);
  }
  return true;
}

function isUniqueNoDataStructues(str) { // trades speed for space
  let length = str.length;

  for (let i = 0; i < length - 1; i++) {
    for (let j = i + 1; j < length; j++) {
      if (str[i] == str[j]) {
        return false;
      }
    }
  }
  return true;
}

describe('isUnique', function() {
  let dataExpectedTrue = ['abcd', 'jose', 'rojas', ' '];
  let dataExpectedFalse = ['hello', 'good', 'buddy', '  '];

  for (let str of dataExpectedTrue) {
    it(`${str} is unique`, function() {
      assert.isTrue(isUniqueNoDataStructues(str));
    });
  }

  for (let str of dataExpectedFalse) {
    it(`${str} is not unique`, function() {
      assert.isFalse(isUniqueNoDataStructues(str));
    });
  }
});
