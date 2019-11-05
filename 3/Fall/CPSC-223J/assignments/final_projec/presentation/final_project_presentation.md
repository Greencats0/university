---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
output: powerpoint_presentation
---

# Archive Manager Clone

![](assets/example_baseline)

Jared Dyreson

CPSC-223J @ 08:00 - 09:50 TR

# Objective

- This project was meant to clone a pre-existing tool available in most GNOME Desktop Environments.
- Cause I thought it would be easy. It wasn't.
- I have an affinity for the UNIX file system

# Feature 1 : Creating an empty Zip Archive

```java
public void create_empty_archive(String path_to_file) throws IOException{
        File zip_file = new File(path_to_file);
        FileOutputStream stream = new FileOutputStream(zip_file);
        BufferedOutputStream buffered = new BufferedOutputStream(stream);
        ZipOutputStream zip_stream = new ZipOutputStream(stream);
        zip_stream.close();
}
```

- Essentially this program only needs to open a file and write a small section of data to the file header
- This sequence of bytes denotes a zip archive

```
0000000 4b50 0605 0000 0000 0000 0000 0000 0000
0000010 0000 0000 0000                         
0000016
```

# Feature 1 : Creating an Empty Zip Archive [Part 2]

- We throw an IOException because the file may be used by another program or other possible race conditions

# 
