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

        public void zip_contents(List<String> file_contents, String path_to_file) throws IOException{
                FileOutputStream file_stream = new FileOutputStream(path_to_file);
                ZipOutputStream zip_out = new ZipOutputStream(file_stream);
                File destination_zip = new File(path_to_file);
                if(destination_zip.exists()){
                        System.out.println("File already exists");
                        return;
                }

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
}
