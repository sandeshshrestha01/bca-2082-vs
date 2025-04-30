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
return 0;
}

Saroj Bhandari | Aadim College
