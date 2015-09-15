/* File Name: KUStudent.java
 * Author: Stephen Longofono 2776831
 * Assignment:   EECS-168 lab08
 * Description:  Create a class to construct students, with variables for first name, last name
 * 					student id, and dept.  Create methods to set name, id, dept.  Create methods
 * 					to get first name, last name, id, and dept.  Do not handle input/output.
 * Date: 10-27-2014
 */
public class KUStudent {
	
	private String stud_fname;
	private String stud_lname;
	private String stud_kuid;
	private String stud_dept;
	
	public void set_name(String fname, String lname){
		
		stud_fname = fname;
		stud_lname = lname;
		
	}
	
	public void set_kuinfo(String kuid, String dept){
		
		stud_kuid = kuid;
		stud_dept = dept;
		
	}
	
	public String get_fname(){
		
		return stud_fname;
		
	}
	
	public String get_lname(){
		
		return stud_lname;
		
	}
	
	public String get_id(){
		
		return stud_kuid;
		
	}

	public String get_dept(){
	
	return stud_dept;
	
	}

}
