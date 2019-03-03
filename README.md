# Run Length Encoded

Run length encoding (RLE) is a very simple form of lossless data compression
which runs on sequences having same value occurring many consecutive times and
it encode the sequence to store only a single value and its count.

Given an input string, returns the Run Length Encoded string for the input string.
For example, if the input string is “wwwwaaadexxxxxx”, then the program return “w4a3dex6”.

# Run Length Decoded

Given an input string, returns the Run Length Decoded string for the input string.
For example, if the input string is “w4a3d1e1x6” or "w4a3dex6" or "4w3a1d1e6x" or "4w3ade6x",
then the function return “wwwwaaadexxxxxx”.
