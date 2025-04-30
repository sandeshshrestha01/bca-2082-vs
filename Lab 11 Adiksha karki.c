#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
FILE *fp;
char filename[] = "example.txt";
int i; /* Declare i here for for-loop iterations */
/********************
* Writing to a Text File
********************/
/* Open file in write mode ("w") */
fp = fopen(filename, "w");
if (fp == NULL) {
perror("Error opening file for writing");
exit(EXIT_FAILURE);
}
/* Write to the file using fprintf(), fputs(), and
fputc() */
fprintf(fp, "Hello, file handling in C!\n");
fputs("This is another line using fputs.\n", fp);
fputc('A', fp);
fputc('\n', fp);
/* Close the file after writing */
fclose(fp);
/********************
* Reading from a Text File using fgetc()
********************/
fp = fopen(filename, "r");
if (fp == NULL) {
perror("Error opening file for reading");
exit(EXIT_FAILURE);
}
printf("Reading file using fgetc():\n");
int ch;
while ((ch = fgetc(fp)) != EOF) {
putchar(ch);
}
fclose(fp);
/********************
* Reading from a Text File using fgets()
********************/
fp = fopen(filename, "r");
if (fp == NULL) {
perror("Error opening file for reading with fgets");
exit(EXIT_FAILURE);
}
printf("\n\nReading file using fgets():\n");
char buffer[256];
while (fgets(buffer, sizeof(buffer), fp) != NULL) {
printf("%s", buffer);
}
fclose(fp);
/********************
* Binary File Handling with fwrite() and fread()
********************/
char binaryFile[] = "binary.dat";
int numbers[5] = {1, 2, 3, 4, 5};
int numbersRead[5] = {0};
/* Open binary file for writing ("wb") */
fp = fopen(binaryFile, "wb");
if (fp == NULL) {
perror("Error opening binary file for writing");
exit(EXIT_FAILURE);
}
/* Write array of integers to the binary file */
fwrite(numbers, sizeof(int), 5, fp);
fclose(fp);
/* Open binary file for reading ("rb") */
fp = fopen(binaryFile, "rb");
if (fp == NULL) {
perror("Error opening binary file for reading");
exit(EXIT_FAILURE);
}
/* Read the integers from the binary file */
fread(numbersRead, sizeof(int), 5, fp);
fclose(fp);
printf("\nBinary file contents (using fread):\n");
for (i = 0; i < 5; i++) {
printf("%d ", numbersRead[i]);
}
printf("\n");
/********************
* Using fseek(), ftell(), and rewind()
********************/
fp = fopen(filename, "r");
if (fp == NULL) {
perror("Error opening file for fseek demo");
exit(EXIT_FAILURE);
}
/* Move file pointer to 10th byte from the beginning */
if (fseek(fp, 10, SEEK_SET) != 0) {
perror("fseek error");
exit(EXIT_FAILURE);
}
/* ftell() returns the current file pointer position */
long pos = ftell(fp);
printf("\nFile pointer position after fseek: %ld\n",
pos);
/* Read and display content from the new position */
printf("Content from position %ld:\n", pos);
while ((ch = fgetc(fp)) != EOF) {
putchar(ch);
}
fclose(fp);
printf("\nName: Adiksha karki");
return 0;
}
