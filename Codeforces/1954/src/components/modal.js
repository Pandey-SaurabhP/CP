import React, { useState } from 'react';
import ReCAPTCHA from 'react-google-recaptcha';

const Modal = ({ isOpen, onClose, onSubmit, newIssue, handleNewIssueChange }) => {
    const [captchaVerified, setCaptchaVerified] = useState(false);

    const handleVerifyCaptcha = () => {
        setCaptchaVerified(true);
    };

    const handleSubmit = () => {
        // Check if CAPTCHA is verified


        if (!captchaVerified) {
            alert('Please complete the CAPTCHA verification.');
            return;
        }

        // // Proceed with form submission

        onSubmit();
    };

    return (
        isOpen && (
            <div className="modal">
                <div className="modal-content">
                    <span className="close" onClick={onClose}>&times;</span>
                    <h2>Add New Issue</h2>
                    <input
                        type="text"
                        placeholder="Subject"
                        value={newIssue}
                        onChange={handleNewIssueChange}
                        className="issue-headline"
                    />

                    <br /><br />

                    <div>Acting Authority</div>
                    <br />
                    <select>
                        <option>Central Bureau of Investigation</option>
                        <option>National Crime Investigation Bureau</option>
                        <option>Crime Research Investigation Agency of India</option>
                        <option>IGI</option>
                    </select>

                    <br /><br />

                    <input
                        type="text"
                        placeholder="Description"
                        value={newIssue}
                        onChange={handleNewIssueChange}
                        className="issue-description"
                    />
                    <br /><br /><br />

                    <ReCAPTCHA
                        sitekey="6Ld05popAAAAAOQ2c2Ry4BtVRhEYFHOflsoU5NSs"
                        render="explicit"
                        verifyCallback={handleVerifyCaptcha}
                    />

                    <button onClick={handleSubmit} className="issue-submit">Submit</button>
                </div>
            </div>
        )
    );
};

export default Modal;
