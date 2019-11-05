/*

Jared Dyreson
CWID: 889546529
FileHandler.java -> 

*/
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import java.io.File;
import java.text.SimpleDateFormat;
import java.text.MessageFormat;

// CONTENTS
// Get specific information about files in the zip buffer
// file name (relative and absolute)
// modification date
// mime type (what kind of file is it)
// current file size
// return the following information into a string that can
// be used in a JLabel object


public class FileHandler {
        // Auto generated with caffine and networking.service

        private String path = "";
        private File file; 

        public FileHandler(String path_to_file){
                this.path = path_to_file;
                this.file = new File(this.path);
        }

        public FileHandler(File file_path_object){
                this.file = file_path_object;
                this.path = this.get_path();
        }

        public String get_path(){
                return this.file.getName();
        }
        public String get_absolute_path(){
                if(this.file.exists()){ return this.file.getAbsolutePath(); }
                return "";
        }
        public String get_last_modified(){
                SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
                return formatter.format(this.file.lastModified());
        }
        public String get_mime_type() throws IOException{
                if(this.file.isDirectory()){ return "dir"; }
                Path source = Paths.get(this.path);
                return Files.probeContentType(source);
        }

        public String get_file_size(){
                return String.valueOf(this.file.length());
        }

        public String row_information() throws IOException{
                return MessageFormat.format("{0}\t\t\t\t{1}\t\t{2}\t\t\t\t{3}", this.get_path(), this.get_file_size(), this.get_mime_type(), this.get_last_modified());
        }

        public static void main(String args[]){
                File[] files_in_wd = new File(".").listFiles();
                for(int i = 0; i < files_in_wd.length; ++i){
                        FileHandler f = new FileHandler(files_in_wd[i]);
                        try{
                                System.out.println(f.row_information());
                        }
                        catch(Exception error){
                                System.out.println(error);
                        }
                }


        }
}
