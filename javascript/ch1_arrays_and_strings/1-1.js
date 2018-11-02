/*
Cracking the Coding Interview Question 1.1 Is Unique

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
*/

var assert = require('chai').assert;

function isUnique(str) {
    return new Set(str).size == str.length;  // set does not store duplicates
}

function isUniqueNoDataStructues(str) {  // trades speed for space
    for (let i = 0; i < str.length - 1; ++i) {
        for (let j = i + 1; j < str.length; ++j) {
            if (str.charAt(i) == str.charAt(j)) {
                return false;
            }
        }
    }

    return true;
}

describe('isUnique', function() {
    let dataExpectedTrue = ['a', 'aA', '', ' '];
    let dataExpectedFalse = ['aa', 'aba', '  '];

    for (let str of dataExpectedTrue) {
        it(`checks if '${str}' is unique`, function() {
            assert.isTrue(isUnique(str));
        });
    }

    for (let str of dataExpectedFalse) {
        it(`checks if '${str}' is not unique`, function() {
            assert.isFalse(isUnique(str));
        });
    }
});
