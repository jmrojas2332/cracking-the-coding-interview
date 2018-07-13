/*
Cracking the Coding Interview Question 1.1 Is Unique

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
*/

var assert = require('chai').assert;

describe('isUnique', function() {
  let dataExpectedTrue = ['abcd', 'jose', 'rojas', ' '];
  let dataExpectedFalse = ['hello', 'good', 'buddy', '  '];

  for (let str of dataExpectedTrue) {
    it(`${str} is unique`, function() {
      assert.isTrue(isUnique(str));
    });
  }

  for (let str of dataExpectedFalse) {
    it(`${str} is not unique`, function() {
      assert.isFalse(isUnique(str));
    });
  }
});

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
