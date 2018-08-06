

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   // Read from entries within UrlsToVerify.txt
	   Scanner scanner = new Scanner(getClass().getResourceAsStream("UrlsToVerify.txt"));
	   String s = new String();

	   while(scanner.hasNextLine()){
		   String[] input_details = new String[2];
		   s = scanner.nextLine();
		   input_details = s.split("\t");
		   String result;
		   
		   if (urlVal.isValid(input_details[0])) {
			   result = "valid";
		   } else {
			   result = "invalid";
		   }
		   System.out.println(input_details[0] + " expected: " + input_details[1] + " actual: " + result);		   
	   }   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
