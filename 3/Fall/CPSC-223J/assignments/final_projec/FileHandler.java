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

public class FileHandler {
        // Auto generated with caffine and networking.service
        
        private String path = "";
        private File file; 

        public FileHandler(String path_to_file){
                this.path = path_to_file;
                this.file = new File(this.path);
        }

        public String get_path(){
                return path;
        }
        public String get_absolute_path(){
                if(this.file.exists()){
                        return this.file.getAbsolutePath();
                }
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

        public static void main(String args[]){
                FileHandler f = new FileHandler("temp/");
                try{
                        System.out.println(f.get_mime_type());
                        System.out.println(f.get_last_modified());
                        System.out.println(f.get_absolute_path());
                }
                catch(Exception error){
                        System.out.println(error);
                }

        }
}
