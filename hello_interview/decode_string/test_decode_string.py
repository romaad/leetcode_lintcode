import unittest
from decode_string import decode_string

class TestDecodeString(unittest.TestCase):
    def test_single_brackets(self):
        self.assertEqual(decode_string("3[a]2[bc]"), "aaabcbc")
        
    def test_nested_brackets(self):
        self.assertEqual(decode_string("3[a2[c]]"), "accaccacc")
        
    def test_trailing_characters(self):
        self.assertEqual(decode_string("2[abc]3[cd]ef"), "abcabccdcdcdef")
        
    def test_no_brackets(self):
        self.assertEqual(decode_string("abc"), "abc")
        
    def test_multi_digit_number(self):
        self.assertEqual(decode_string("10[a]"), "aaaaaaaaaa")
        
    def test_complex_nested(self):
        self.assertEqual(decode_string("2[2[b]]"), "bbbb")

if __name__ == '__main__':
    unittest.main()
