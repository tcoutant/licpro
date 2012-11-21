void parcourirFileSystem(char * repertoire)
{
  struct stat sb;
  DIR *dir;
  if ((dir = opendir(repertoire)) != NULL)
  {
    struct dirent *entry = readdir(dir);

    while(entry)
    {
      if((strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0))
      {

      char s[FILENAME_MAX];
      sprintf(s, "%s/%s", repertoire, entry->d_name);

      lstat(s, &sb);

      int type = S_ISDIR(sb.st_mode);
      if(type == 1)
      {
	printf("%s\n", s);
	parcourirFileSystem(s);
      }
      }
    entry = readdir(dir);
    }
  closedir(dir);
  }
}
