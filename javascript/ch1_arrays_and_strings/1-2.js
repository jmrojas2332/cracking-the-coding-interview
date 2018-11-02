/*
Cracking the Coding Interview Question 1.2 Check Permutation

Given two strings, write a method to decide if one is a permutation of the other.
*/

var assert = require('chai').assert;

function isPermutation(str1, str2) {
    let charCount = new Map();

    for (let char of str1) {
        char in charCount ? charCount[char] += 1 : charCount[char] = 1;
    }

    for (let char of str2) {
        if (charCount[char] > 0) {
            charCount[char] -= 1;
        } else {
            return false;
        }
    }

    return true;
}

describe('isPermutation', function () {
    const dataExpectedTrue = [['a','a'], ['ab', 'ba'], ['001', '100'], [' a', 'a ']];
    const dataExpectedFalse = [['a', 'A'], ['ab', 'ac'], ['', ' ']];

    for (let [str1, str2] of dataExpectedTrue) {
        it(`checks if '${str1}' and '${str2}' are permutations of each other`, function () {
            assert.isTrue(isPermutation(str1, str2));
        });
    }

    for (let [str1, str2] of dataExpectedFalse) {
        it(`checks if '${str1}' and '${str2}' are not permutations of each other`, function () {
            assert.isFalse(isPermutation(str1, str2));
        });
    }
});
