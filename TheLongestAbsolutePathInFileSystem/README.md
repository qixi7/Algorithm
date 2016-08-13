##README.md 
-------------
#求文件系统最长绝对路径问题
-------------

###问题描述
假设我们抽象文件系统由一个字符串在以下方式：

字符串"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" 代表：

dir
    subdir1
    subdir2
        file.ext

一个目录下包含一个空子目录subdir1和一个包含文件file.ext的子目录subdir2.

现在我们感兴趣的是在文件系统中找到最长(字符数)绝对路径。比如字符串"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"代表：

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

的最大绝对路径是"dir/subdr2/subsubdir2/file.ext"，它的长度是30。

问题:给定一个字符串代表文件系统在上面的格式,返回文件系统中长度最长的绝对路径长度。简单的说，

就是一个有效以一个文件(包含"."以及扩展后缀名)结尾的文件路径。

要求：O(n)的时间复杂度，字符串的大小是n。

注意：需要注意的是如果存在路径aaaaaaaaaaaaaaaaaaaaa/sth.png的话，路径a/aa/aaa/file1.txt并不是正确的答案。

###思路
    用一个变量来记录最大长度maxLen，借助一个栈用来存放每一层去除掉"\t"的子串。用"\n"分离各个字符串，

先根据"\t"判断截取到的子串的层数，再获取该层上的去除掉"\t"的子串，再判断这个字串是最终是文件还是文件夹，如果是文件的话就计算当前已知最大路径长度和代表该文件的路径长度比较，更新maxLen。

如果是截取到的子串是文件夹的话，判断栈顶的路径的层数如果大于等于当前子串层数，就pop掉栈顶子串。

再把当前的子串push进栈顶。这样做是为了在遍历的时候将每一个文件路径都比较一遍。

这样遍历完一次就能得出结果。符合O(n)。

　　最后返回maxLen即是最大路径长度。

###这里仅给出Java代码
