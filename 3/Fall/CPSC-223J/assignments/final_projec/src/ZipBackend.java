/*

Jared Dyreson
CWID: 889546529
ZipBackend.java -> 

*/

import java.io.*;
import java.util.*;
import java.util.zip.*;

public class ZipBackend {
        // Auto generated with caffine and accounts-daemon.service
        
        private ZipOutputStream zip_stream_for_class;
        private String path = "";

        //public ZipBackend(String zip_path){
                //this.path = zip_path;
        //}

        public void zip_contents(List<String> file_contents, String path_to_file) throws IOException{
                FileOutputStream file_stream = new FileOutputStream(path_to_file);
                ZipOutputStream zip_out = new ZipOutputStream(file_stream);
                File destination_zip = new File(path_to_file);

                for(String path : file_contents){
                        File zip_this_file = new File(path);
                        FileInputStream input_stream = new FileInputStream(zip_this_file);
                        ZipEntry zip_entry = new ZipEntry(zip_this_file.getName());
                        zip_out.putNextEntry(zip_entry);

                        byte[] bytes = new byte[1024];
                        int len;
                        while((len = input_stream.read(bytes)) >= 0){
                                zip_out.write(bytes, 0, len);
                        }
                        input_stream.close();
                }
                zip_out.close();
                file_stream.close();
        }

        public void create_empty_archive(String path_to_file) throws IOException{
                File zip_file = new File(path_to_file);
                FileOutputStream stream = new FileOutputStream(zip_file);
                BufferedOutputStream buffered = new BufferedOutputStream(stream);
                ZipOutputStream zip_stream = new ZipOutputStream(stream);

                //ZipEntry fake_entry = new ZipEntry("fake_meta");
                //zip_stream.putNextEntry(fake_entry);
                //zip_stream.closeEntry();
                zip_stream.close();
        }

        public void dump_contents(File source, String destination){
               File dest = new File(destination);
               // unzip file article -> https://www.journaldev.com/960/java-unzip-file-example
               FileInputStream file_input_stream_handler;
               if(!dest.isDirectory()){ dest.mkdirs();}

        }

        //public void list_contents(String path_to_archive){
                //// this will only print with depth of 1

                
        //}
}
