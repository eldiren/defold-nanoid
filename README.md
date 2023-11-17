## What is NanoID?
NanoID is a tiny, secure URL-friendly unique string ID generator.  
It's **safe**. It uses cryptographically strong random APIs that guarantees proper distribution of symbols.  
And it's **compact**. It uses a larger alphabet than the standard UUID (`A-Za-z0-9_-`), and has a similar number of unique IDs in just 21 symbols instead of 36.

## Usage
`simple()` - generate an id of default length (21) using the default character set  
```lua
local simple = nanoid.simple() 
print(simple)
```

`generate(size)` - generate an id of custom length using the default character list  

```lua
local generate = nanoid.generate(5)
print(generate)
```

`custom(custom_alphs, size)` - generate an id of custom length using a custom character set  

```lua
local custom = nanoid.custom("abcde", 7)
print(custom)
```